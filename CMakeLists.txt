cmake_minimum_required(VERSION 3.10)
project(autoaim)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(autoaim
        hik_camera/hik_camera/HikCam.cpp
        Detector/src/detector.cpp
        Detector/include/detector.h
        Detector/include/serial.h
        Detector/src/serial.cpp
        Detector/src/classifier.cpp
        Detector/include/classifier.h
        Detector/src/serial.cpp
        Detector/include/classifier.h
        Detector/include/pnp.h
        Detector/src/pnp.cpp
        Detector/src/pnp.cpp
        main.cpp
)

target_link_libraries(autoaim ${OpenCV_LIBS})
#包含海康相机动态链接库
find_library(MVS_LIB libMvCameraControl.so /opt/MVS/lib/64/)
target_link_libraries(autoaim ${MVS_LIB} -lserialport)

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
