//
// Created by mry on 23-7-6.
//

#ifndef RM_SERIAL_H
#define RM_SERIAL_H

#include<list>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
using namespace std;

class Serial
{
public:
    bool open();
    void data_send(double &yaw,double &pitch);
    void send(string &data);
    void recieve(int &recolor,double &speed);

    struct sp_port *serPort;
    string msg;
    char msg_recieve[25];
    double re_yaw,re_pitch;


};

#endif //RM_SERIAL_H
