//
// Created by mry on 23-7-6.
//
#include <iostream>
using namespace std;
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <chrono>
#include "Detector/include/detector.h"
#include "Detector/include/serial.h"
#include "hik_camera/hik_camera/include/HikCam.hpp"
#include <thread>
#include <opencv2/highgui/highgui_c.h>

cv::Mat img;
HikCam h;
void getSrc(){
    while(true){
        h.GetMat(img);
    }
}

int main() {

    h.StartDevice(0);
    h.SetResolution(1280,1024);
    h.SetPixelFormat(17301514);
    h.SetExposureTime(5000);  //曝光
    h.SetFrameRate(120);    //帧率
    h.SetStreamOn();//开始取流

    thread src(getSrc);
    src.detach();

    Detector::LightParams l{0.1, 0.5, 45.0};
    Detector::ArmorParams a{0.7, 0.8, 3.2, 3.2, 5.5, 35.0};
    Detector p(230, l, a);

    Serial s;
    s.open();
    thread s1(&Serial::recieve,&s,ref(p.detect_color),ref(p.speed));
    s1.detach();

    thread s2(&Serial::data_send,&s,ref(p.send_yaw),ref(p.send_pitch),ref(p.pitch));
    s2.detach();

    thread s3(&Serial::send,&s,ref(s.msg));
    s3.detach();


    while (true) {
//        auto start = std::chrono::high_resolution_clock::now();
        cv::namedWindow("image", CV_WINDOW_AUTOSIZE);

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

//        auto end = std::chrono::high_resolution_clock::now();
//        std::chrono::duration<double> total = end - start;
//        cout << "fps：" << 1/total.count() << endl;
//        std::string fps("fps : ");
//        cv::putText(img, fps+to_string(1/total.count()), cv::Point2i(20, 370), cv::FONT_HERSHEY_SIMPLEX, 0.8,
//                    cv::Scalar(0, 255, 255), 2);
    }
}





