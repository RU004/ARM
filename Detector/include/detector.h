//
// Created by mry on 23-7-6.
//

#ifndef RM_DETECTOR_H
#define RM_DETECTOR_H

// OpenCV
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>

// STD
#include <cmath>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <map>

const int RED = 0;
const int BLUE = 1;

enum class ArmorType { SMALL, LARGE, INVALID };       //枚举类型
const std::string ARMOR_TYPE_STR[3] = {"small", "large", "invalid"};

struct Light : public cv::RotatedRect      //RotatedRect 用于创建旋转矩形
{
    Light() = default;
    explicit Light(cv::RotatedRect box) : cv::RotatedRect(box)
    {
        cv::Point2f p[4];
        box.points(p);    //返回旋转矩形的4个顶点
        std::sort(p, p + 4, [](const cv::Point2f & a, const cv::Point2f & b) { return a.y < b.y; });   //排序
        top = (p[0] + p[1]) / 2;
        bottom = (p[2] + p[3]) / 2;

        length = cv::norm(top - bottom);
        width = cv::norm(p[0] - p[1]);

        tilt_angle = std::atan2(std::abs(top.x - bottom.x), std::abs(top.y - bottom.y));
        tilt_angle = tilt_angle / CV_PI * 180;

    }

    int color{};
    cv::Point2f top, bottom;
    double length{};
    double width{};
    float tilt_angle{};

};

struct Armor
{
    Armor() = default;
    Armor(const Light & l1, const Light & l2)
    {
        if (l1.center.x < l2.center.x) {
            left_light = l1, right_light = l2;
        } else {
            left_light = l2, right_light = l1;
        }
        center = (left_light.center + right_light.center) / 2;
    }

    // Light pairs part
    Light left_light, right_light;
    cv::Point2f center;
    ArmorType type;

    // Number part
    cv::Mat number_img;
    std::string number;
    float confidence;
    std::string classfication_result;

};

class Detector
{
public:
    struct LightParams
    {
        // width / height
        double min_ratio;
        double max_ratio;
        // vertical angle
        double max_angle;
    };

    struct ArmorParams
    {
        double min_light_ratio;
        // light pairs distance
        double min_small_center_distance;
        double max_small_center_distance;
        double min_large_center_distance;
        double max_large_center_distance;
        // horizontal angle
        double max_angle;
    };

    Detector(const int & bin_thres,const LightParams & l, const ArmorParams & a);
//    Detector(const int & bin_thres,const int & color,const LightParams & l, const ArmorParams & a);

    void Thread();
    std::vector<Armor> detect(const cv::Mat & input);
    cv::Mat preprocessImage(const cv::Mat & input);
    cv::Mat read_morphology(const cv::Mat & binary);
    std::vector<Light> findLights(const cv::Mat & rbg_img, const cv::Mat & dst_img);
    std::vector<Armor> matchLights(const std::vector<Light> & lights);
    double increase(double speed,double pitch,double distance);

    // For debug usage
    cv::Mat getAllNumbersImage();
    void drawResults(cv::Mat & img);
    void autodraw(cv::Mat input, std::string text, int x,int y);

    int binary_thres;
    cv::Mat binary_img;
    cv::Mat dst;
    LightParams l;
    ArmorParams a;
    double yaw;                // 侧航角（x/z）
    double pitch;              // 俯仰角（y/z）
    double new_pitch;          //弹道补偿后new_pitch
    double distance;           // 距离
    double raise;

//==========recieve==============================

    int detect_color;
    double speed;

//===========send================================

    double send_yaw,send_pitch;



private:
    bool isLight(const Light & possible_light);
    bool containLight(const Light & light_1, const Light & light_2, const std::vector<Light> & lights);
    ArmorType isArmor(const Light & light_1, const Light & light_2);

    std::vector<Light> lights_;
    std::vector<Armor> armors_;
};

#endif //RM_DETECTOR_H
