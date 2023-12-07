cmake_minimum_required(VERSION 3.10)
project(autoaim)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(CSerialPort REQUIRED)
include_directories(${CSerialPort_INCLUDE_DIR})

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
        visionSerial-main/include/packet.h
        visionSerial-main/src/serial.cpp
        hero.cpp
)


find_library(MVS_LIB libMvCameraControl.so /opt/MVS/lib/64/)
target_link_libraries(autoaim ${OpenCV_LIBS} ${MVS_LIB} -lserialport ${CSerialPort_LIBRARY} -pthread )


