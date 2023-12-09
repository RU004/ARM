//
// Created by mry on 23-7-6.
//
#include <iostream>
using namespace std;
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Detector/include/detector.h"
#include "hik_camera/hik_camera/include/HikCam.hpp"
#include <opencv2/highgui/highgui_c.h>

int main() {

    cv::Mat img;
    cv::VideoCapture video;
    video.open("../Detector/docs/666.avi");
    if (!video.isOpened()) {
        cout << "can't open video" << endl;
        return false;
    }

    Detector::LightParams l{0.1, 0.5, 45.0};
    Detector::ArmorParams a{0.7, 0.8, 3.2, 3.2, 5.5, 35.0};
    Detector armor(230, l, a);

    while (video.read(img)){
        if (img.empty())
            break;

//        auto start = std::chrono::high_resolution_clock::now();
        cv::namedWindow("image", CV_WINDOW_AUTOSIZE);

//        cv::Mat binary = p.preprocessImage(img);
//        cv::Mat dst = p.read_morphology(binary);
//        imshow("binary",binary);
//        imshow("dst",dst);

        armor.detect(img);
        armor.getAllNumbersImage();
        armor.drawResults(img);

        imshow("image", img);
        if (cv::waitKey(10) == 27)        //按下Esc建结束
            break;

//        auto end = std::chrono::high_resolution_clock::now();
//        std::chrono::duration<double> total = end - start;
//        cout << "fps：" << 1/total.count() << endl;
//        std::string fps("fps : ");
//        cv::putText(img, fps+to_string(1/total.count()), cv::Point2i(20, 370), cv::FONT_HERSHEY_SIMPLEX, 0.8,
//                    cv::Scalar(0, 255, 255), 2);
    }
}





