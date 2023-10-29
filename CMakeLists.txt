cmake_minimum_required(VERSION 3.10)
project(RM)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(RM main.cpp hik_camera/hik_camera/HikCam.cpp Detector/src/detector.cpp Detector/include/detector.h Detector/include/serial.h Detector/src/serial.cpp Detector/src/classifier.cpp Detector/include/classifier.h Detector/src/serial.cpp Detector/include/classifier.h Detector/include/pnp.h Detector/src/pnp.cpp Detector/src/pnp.cpp)

target_link_libraries(RM -I/usr/local/include/opencv4 -L/usr/local/lib -lopencv_dnn -lopencv_stitching -lopencv_objdetect -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core)

#包含海康相机动态链接库
find_library(MVS_LIB libMvCameraControl.so /opt/MVS/lib/64/)
target_link_libraries(RM ${MVS_LIB} -lserialport)

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
