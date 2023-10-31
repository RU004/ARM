//
// Created by mry on 23-7-6.
//
#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "Detector/include/detector.h"
#include "Detector/include/serial.h"
#include "hik_camera/hik_camera/include/HikCam.hpp"
#include <thread>

int main() {

//    cv::VideoCapture video;
//    video.open("../Detector/docs/666.avi");
//    if (!video.isOpened()) {
//        cout << "can't open video" << endl;
//        return false;
//    }

    cv::Mat img;

//    while (video.read(img)){
//        if (img.empty())
//            break;

    HikCam h;
    h.StartDevice(0);
    h.SetResolution(1280,1024);
    h.SetPixelFormat(17301514);
    h.SetExposureTime(5000);
    h.SetFrameRate(120);
    h.SetStreamOn();//开始取流

    Detector::LightParams l{0.1, 0.5, 45.0};
    Detector::ArmorParams a{0.7, 0.8, 3.2, 3.2, 5.5, 35.0};
    Detector p(230, l, a);
//    Detector p(230, 1, l, a);

//    p.Thread();

    Serial s;
    s.open();
    thread s1(&Serial::recieve,&s);
    p.detect_color = (s.re_color=='R')?0:1;
    p.speed = s.re_speed;
    s1.detach();

    thread s2(&Serial::data_send,&s,p.send_yaw,p.send_pitch);
    s2.detach();

    thread s3(&Serial::send,&s,s.msg);
    s3.detach();

    while (1) {
        namedWindow("image",cv::WINDOW_NORMAL);
        h.GetMat(img);

//      cv::Mat img = cv::imread("/home/mry/RM/Detector/docs/22.jpg");


//        cv::Mat binary = p.preprocessImage(img);
//        cv::Mat dst = p.read_morphology(binary);
//        imshow("binary",binary);
//        imshow("dst",dst);

        p.detect(img);
        p.getAllNumbersImage();
        p.drawResults(img);

        imshow("image", img);
        if (cv::waitKey(10) == 27)        //按下Esc建结束
            break;
    }
}





