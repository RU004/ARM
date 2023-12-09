//
// Created by promise on 11/3/23.
//

#ifndef SERIAL_TEST_PACKET_H
#define SERIAL_TEST_PACKET_H

#include <cstdint>
#include <vector>
#include <algorithm>
#pragma pack(2)
struct visionMsg{
    uint16_t head;
    double aimYaw;               // 目标Yaw
    double aimPitch;             // 目标Pitch
};

struct robotMsg{
    uint16_t head;
    uint8_t mode;               // 自瞄模式 0-装甲板 1-小符 2-大符
    uint8_t foeColor;           // 敌方颜色 0-blue 1-red
    double robotYaw;               // 自身Yaw
    double robotPitch;             // 自身Pitch
    double muzzleSpeed;          // 弹速
};

union visionArray{
    struct visionMsg msg;
    uint8_t array[sizeof(struct visionMsg)];
};

union robotArray{
    struct robotMsg msg;
    uint8_t array[sizeof(struct robotMsg)];
};
#pragma pack()

#endif //SERIAL_TEST_PACKET_H
