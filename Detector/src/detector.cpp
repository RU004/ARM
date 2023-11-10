//
// Created by mry on 23-7-6.
//
#include<iostream>
using namespace std;

// OpenCV
#include <opencv2/core.hpp>
#include <opencv2/core/base.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

// STD
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

#include "../include/detector.h"
#include "../include/pnp.h"
#include "../include/classifier.h"

Detector::Detector(
        const int & bin_thres, const LightParams & l, const ArmorParams & a)
        : binary_thres(bin_thres), l(l), a(a)
{
}

//Detector::Detector(
//        const int & bin_thres, const int & color, const LightParams & l, const ArmorParams & a)
//        : binary_thres(bin_thres), detect_color(color), l(l), a(a)
//{
//}



std::vector<Armor> Detector::detect(const cv::Mat & input)
{
    binary_img = preprocessImage(input);
    dst = read_morphology(binary_img);
    lights_ = findLights(input, dst);
    armors_ = matchLights(lights_);

//--------------------数字识别--------------------------------------------------------------------------------------

    NumberClassifier q("../Detector/model/mlp.onnx","../Detector/model/label.txt",
                       0.7,std::vector<std::string>{"negative"});
    if (!armors_.empty()) {
        q.extractNumbers(input, armors_);
        q.classify(armors_);
    }
    if(armors_.empty()){
        send_yaw = 0;
        send_pitch = 0;
    }


//--------------------PNP解算---------------------------------------------------------------------------------------
//    std::array<double, 9> camera_matrix {1572.4, 0.0, 655, 0.0, 1572.4, 503.4, 0.0, 0.0, 1.0};
//    std::vector<double> dist_coeffs {-0.313818281448022, 0.106042483, 0, 0, 0};
    std::array<double, 9> camera_matrix {1869.074197, 0.0, 664.6998242, 0.0, 1867.898354, 518.0525069, 0.0, 0.0, 1.0};
    std::vector<double> dist_coeffs {-0.16311607346, 0.255155351, 0, 0, 0};
    cv::Mat rvec ;          //旋转向量
    cv::Mat tvec ;          //平移向量

    PnPSolver m(camera_matrix,dist_coeffs);
    for(const auto armors : armors_){

        m.solvePnP(armors,rvec,tvec);

        double x = tvec.at<double>(0, 0), y = tvec.at<double>(1, 0), z = tvec.at<double>(2, 0);
        yaw = atan2(x , z) * 180.0 / CV_PI;
        pitch = atan2(-y, sqrt(x*x + z*z)) * 180.0 / CV_PI;
        distance = sqrt(x*x + y*y + z*z);

//----------------------弹道补偿-------------------------------------------------------------------------------
        if(speed<1) speed=30;
        new_pitch = increase(speed,pitch,distance);
//        new_pitch = increase(20,pitch,distance);

        if(new_pitch<0){
            raise = tan(abs(pitch)*CV_PI/180)*distance - tan(abs(new_pitch)*CV_PI/180)*distance;
        }
        else raise = -(tan(abs(pitch)*CV_PI/180)*distance - tan(abs(new_pitch)*CV_PI/180)*distance);

//        cout<<"Raise: "<<setprecision(3)<<raise<<"m"<<endl;

        if(armors_.size()>1){
            opt1 = (yaw+new_pitch)/2;
            if(opt==0 || opt1<opt){
                opt = opt1;
                send_yaw = yaw;
                send_pitch = new_pitch;
            }
        }

        else{
            send_yaw = yaw;
            send_pitch = new_pitch;
        }

//        if(abs(yaw)<=2)send_yaw = 0;
//        else send_yaw = yaw;
//        if(abs(new_pitch)<=2)send_pitch = 0;
//        else send_pitch = new_pitch;

//---------------------for debug---------------------------------------------------------------------------------------
        std::string X("x : ");
        std::string Y("y : ");
        std::string Z("z : ");
        std::string yaw_("yaw     : ");
        std::string pitch_("pitch   : ");
        std::string new_pitch_("new_pitch    : ");
        std::string dis("distance : ");
        std::string raise_("raise : ");

        autodraw(input,X+to_string(x),20,50);
        autodraw(input,Y+to_string(y),20,90);
        autodraw(input,Z+to_string(z),20,130);
        autodraw(input,yaw_+to_string(yaw),20,170);
        autodraw(input,pitch_+to_string(pitch),20,210);
        autodraw(input,new_pitch_+to_string(new_pitch),20,250);
        autodraw(input,dis+to_string(distance),20,290);
        autodraw(input,raise_+to_string(raise),20,330);

    }

    return armors_;
}

cv::Mat Detector::preprocessImage(const cv::Mat & rgb_img)
{
    cv::Mat gray_img;
    cv::cvtColor(rgb_img, gray_img, cv::COLOR_RGB2GRAY);

    cv::Mat binary_img;
    cv::threshold(gray_img, binary_img, binary_thres, 255, cv::THRESH_BINARY);

    return binary_img;

}
cv::Mat Detector::read_morphology(const cv::Mat & binary)
{
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(1,1));  // 去除多余噪声,
    cv::morphologyEx(binary, dst,cv::MORPH_OPEN, kernel);
    kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, 9));  // 提取垂直直线,去除横向噪声
    cv::morphologyEx(dst, dst,cv::MORPH_OPEN, kernel);
    kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2, 2)) ; // 填充物体中的小洞
    cv::morphologyEx(dst, dst,cv::MORPH_CLOSE, kernel);

//    kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
//    cv::erode(dst, dst, kernel);
//    kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
//    cv::dilate(dst, dst, kernel);

    return dst;

}
std::vector<Light> Detector::findLights(const cv::Mat & rbg_img, const cv::Mat & dst_img)
{
    using std::vector;
    vector<vector<cv::Point>> contours;   //一个双重向量  向量内每个元素保存了一组由连续的Point点构成的点的集合的向量，每一组Point点集就是一个轮廓。 有多少轮廓，向量contours就有多少元素。
    vector<cv::Vec4i> hierarchy;          //hierarchy也是一个向量，向量内每个元素保存了一个包含4个int整型的数组,,和轮廓向量contours内的元素是一一对应的
    cv::findContours(dst_img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);  //只检测最外围轮廓   仅保存轮廓的拐点信息

    vector<Light> lights;

    for (const auto & contour : contours) {
        if (contour.size() < 5) continue;

        auto r_rect = cv::minAreaRect(contour);    //获取对象的*最小*面积包围框  返回值是旋转矩形框中心点的坐标和框的宽高
        auto light = Light(r_rect);

        if (isLight(light)) {
            auto rect = light.boundingRect();                 //返回包围轮廓的矩形的边界信息   返回矩形边界*左上角顶点*的坐标值及矩形边界的宽和高
            if (  // Avoid assertion failed
                    0 <= rect.x && 0 <= rect.width && rect.x + rect.width <= rbg_img.cols && 0 <= rect.y &&
                    0 <= rect.height && rect.y + rect.height <= rbg_img.rows) {
                int sum_r = 0, sum_b = 0;
                auto roi = rbg_img(rect);                      //感兴趣区域
                // Iterate through the ROI
                for (int i = 0; i < roi.rows; i++) {
                    for (int j = 0; j < roi.cols; j++) {   //测试一个点是否在多边形中--------------------判断颜色
                        if (cv::pointPolygonTest(contour, cv::Point2f(j + rect.x, i + rect.y), false) >= 0) {
                            // if point is inside contour
                            sum_r += roi.at<cv::Vec3b>(i, j)[2];
                            sum_b += roi.at<cv::Vec3b>(i, j)[0];
                        }
                    }
                }
                // Sum of red pixels > sum of blue pixels ?
                light.color = sum_r > sum_b ? RED : BLUE;
                lights.emplace_back(light);
            }
        }
    }

    return lights;
}

bool Detector::isLight(const Light & light)
{
    // The ratio of light (short side / long side)
    float ratio = light.width / light.length;

    bool ratio_ok = l.min_ratio < ratio && ratio < l.max_ratio;

    bool angle_ok = light.tilt_angle < l.max_angle;

    bool is_light = ratio_ok && angle_ok;


    return is_light;
}

std::vector<Armor> Detector::matchLights(const std::vector<Light> & lights)
{
    std::vector<Armor> armors;

    // Loop all the pairing of lights
    for (auto light_1 = lights.begin(); light_1 != lights.end(); light_1++) {
        for (auto light_2 = light_1 + 1; light_2 != lights.end(); light_2++) {
            if (light_1->color != detect_color || light_2->color != detect_color) continue;   //*******************************************************************

            if (containLight(*light_1, *light_2, lights)) {
                continue;
            }

            auto type = isArmor(*light_1, *light_2);
            if (type != ArmorType::INVALID) {
                auto armor = Armor(*light_1, *light_2);
                armor.type = type;
                armors.emplace_back(armor);
            }
        }
    }
    return armors;
}

// Check if there is another light in the boundingRect formed by the 2 lights
bool Detector::containLight(
        const Light & light_1, const Light & light_2, const std::vector<Light> & lights)
{
    auto points = std::vector<cv::Point2f>{light_1.top, light_1.bottom, light_2.top, light_2.bottom};
    auto bounding_rect = cv::boundingRect(points);

    for (const auto & test_light : lights) {
        if (test_light.center == light_1.center || test_light.center == light_2.center)continue;

        if (
                bounding_rect.contains(test_light.top) || bounding_rect.contains(test_light.bottom) ||
                bounding_rect.contains(test_light.center)) {
            return true;
        }
    }

    return false;
}

ArmorType Detector::isArmor(const Light & light_1, const Light & light_2)
{
    // Ratio of the length of 2 lights (short side / long side)
    float light_length_ratio = light_1.length < light_2.length ? light_1.length / light_2.length
                                                               : light_2.length / light_1.length;
    bool light_ratio_ok = light_length_ratio > a.min_light_ratio;

    // Distance between the center of 2 lights (unit : light length)
    float avg_light_length = (light_1.length + light_2.length) / 2;
    float center_distance = cv::norm(light_1.center - light_2.center) / avg_light_length;
    bool center_distance_ok = (a.min_small_center_distance <= center_distance &&
                               center_distance < a.max_small_center_distance) ||
                              (a.min_large_center_distance <= center_distance &&
                               center_distance < a.max_large_center_distance);

    // Angle of light center connection
    cv::Point2f diff = light_1.center - light_2.center;
    float angle = std::abs(std::atan(diff.y / diff.x)) / CV_PI * 180;
    bool angle_ok = angle < a.max_angle;

    bool is_armor = light_ratio_ok && center_distance_ok && angle_ok;

    // Judge armor type
    ArmorType type;
    if (is_armor) {
        type = center_distance > a.min_large_center_distance ? ArmorType::LARGE : ArmorType::SMALL;
    } else {
        type = ArmorType::INVALID;
    }

    return type;
}

cv::Mat Detector::getAllNumbersImage()
{
    if (armors_.empty()) {
        return cv::Mat(cv::Size(20, 28), CV_8UC1);
    } else {
        std::vector<cv::Mat> number_imgs;
        number_imgs.reserve(armors_.size());
        for (auto & armor : armors_) {
            number_imgs.emplace_back(armor.number_img);
        }
        cv::Mat all_num_img;
        cv::vconcat(number_imgs, all_num_img);     //vconcat 在垂直方向上连接图像或矩阵
        return all_num_img;
    }
}

void Detector::drawResults(cv::Mat & img)
{
    // Draw Lights
    for (const auto & light : lights_) {

        cv::circle(img, light.top, 3, cv::Scalar(0, 0, 255), 3);
        cv::circle(img, light.bottom, 3, cv::Scalar(0, 0, 255), 3);
        auto line_color = light.color == BLUE ? cv::Scalar(0, 0, 155) : cv::Scalar(155, 0, 0);
        cv::line(img, light.top, light.bottom, line_color, 2);
    }

    // Draw armors
    for (const auto & armor : armors_) {
        cv::line(img, armor.left_light.top, armor.right_light.bottom, cv::Scalar(0, 255, 0), 2);
        cv::line(img, armor.left_light.bottom, armor.right_light.top, cv::Scalar(0, 255,0), 2);
    }

    // Show numbers and confidence
    for (const auto & armor : armors_) {
        cv::putText(img, armor.classfication_result, armor.left_light.top, cv::FONT_HERSHEY_SIMPLEX, 0.8,
                    cv::Scalar(0, 255, 255), 2);
    }

}

void Detector::autodraw(cv::Mat input, std::string text, int x,int y)
{
    cv::putText(input, text, cv::Point2i(x, y), cv::FONT_HERSHEY_SIMPLEX, 0.8,cv::Scalar(0, 255, 255), 2);
}

double Detector::increase(double speed,double pitch,double distance)
{
    double k = 0.03;
    double angle = pitch;
    double judge = pitch;
    double targetPoint = tan(abs(pitch)*CV_PI/180)*distance; //最终目标点
    double tempPoint = tan(abs(pitch)*CV_PI/180)*distance; //临时目标点
    double dropH;

    for(int i = 0;i<15;i++)
    {
        double time;
        double realPoint;
        time = (pow(2.72,k*distance)-1)/(k*speed);

        if(judge<0){
            realPoint = speed*time*sin(abs(angle)*CV_PI/180) + 9.8*time*time/2;
            dropH = realPoint - targetPoint;
            tempPoint -= dropH;
            angle = atan(tempPoint/distance)*180/CV_PI;
        }
        else{
            realPoint = speed*time*sin(angle*CV_PI/180) - 9.8*time*time/2;
            dropH = targetPoint - realPoint;
            tempPoint += dropH;
            angle = atan(tempPoint/distance)*180/CV_PI;
        }

        if(abs(dropH)<0.1)break;
    }

    if(judge<0){
        return -abs(angle);
    }
    else
        return abs(angle);
}





















