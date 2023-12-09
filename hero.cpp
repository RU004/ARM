//
// Created by mry on 23-12-7.
//
//
// Created by mry on 23-7-6.
//
#include <iostream>
using namespace std;
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <chrono>
#include <thread>
#include "hik_camera/hik_camera/include/HikCam.hpp"
#include "Detector/include/detector.h"
#include "visionSerial-main/include/serial.hpp"

cv::Mat img;
HikCam cam;
void getSrc(){
    while(true){
        cam.GetMat(img);
    }
}

visionSerial Serial("/dev/ttyACM0",115200);

int main() {

    cam.StartDevice(0);
    cam.SetResolution(1280,1024);
    cam.SetPixelFormat(17301514);
    cam.SetExposureTime(5000);  //曝光
    cam.SetFrameRate(120);    //帧率
    cam.SetStreamOn();//开始取流

    thread src(getSrc);
    src.detach();

    Serial.sendThread();   // 打开发送线程
    Serial.reciveThread(); // 打开接收线程

    Detector::LightParams l{0.1, 0.5, 45.0};
    Detector::ArmorParams a{0.7, 0.8, 3.2, 3.2, 5.5, 35.0};
    Detector armor(230, l, a);


    while (true) {
//        auto start = std::chrono::high_resolution_clock::now();
        cv::namedWindow("image", CV_WINDOW_AUTOSIZE);


        armor.detect(img);
        armor.getAllNumbersImage();
        armor.drawResults(img);

        cout<<"send_yaw: "<< armor.send_yaw<<endl;
        cout<<"send_pitch: "<< armor.send_pitch<<endl;
        visionMsg msg1 = {armor.send_yaw,armor.send_pitch};
        robotMsg msg2 = {1,false,0,0,20};
        usleep(10000);
        Serial.visionUpdate(&msg1);     // 更新自瞄数据
        Serial.robotUpdate(&msg2);      // 更新机器人数据

        armor.detect_color = msg2.foeColor;
        armor.speed = msg2.muzzleSpeed;
        cout<<"color: "<< armor.detect_color<<endl;
        cout<<"speed: "<< armor.speed<<endl;

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





