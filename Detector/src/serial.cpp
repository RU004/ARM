//
// Created by mry on 23-7-6.
//
#include <iostream>
#include <string>
#include<libserialport.h>
using namespace std;
#include "../include/serial.h"
#include "../include/detector.h"

bool Serial::open() {
    sp_return ret = sp_get_port_by_name("/dev/ttyACM0", &serPort);
//    if(ret != SP_OK)sp_get_port_by_name("/dev/ttyUSB0", &serPort);
    ret = sp_open(serPort,SP_MODE_READ_WRITE);
    if(ret != SP_OK) return false;
    sp_set_baudrate(serPort,115200);
    sp_set_bits(serPort, 8);
    sp_set_parity(serPort,SP_PARITY_NONE);
    sp_set_stopbits(serPort, 1);
    return true;
}

void Serial::data_send(double & yaw,double & pitch)
{
    while(true){

        msg = "A""Y+"+ to_string(yaw) + "P" + to_string(pitch) + "FE";
        msg = "A";
        msg += "Y";
        if(yaw>0)msg += "+";
        else msg += "-";
        msg += isnan(yaw) ? cv::format("%06.2d",0) : (cv::format("%06.2f",abs(yaw)));
        msg += "P";
        if(pitch>0)msg += "+";
        else msg += "-";
        msg += isnan(pitch) ? cv::format("%06.2d",0) : (cv::format("%06.2f",abs(pitch)));
        if(yaw < 5 && abs(pitch) < 5)msg += "F";
        else msg += "N";
        msg += "E";
        cout<<"Send: "<<msg<<endl;
    }
}



void Serial::send(string & data)
{
    while(true){
        sp_nonblocking_write(serPort,data.c_str(),19);
    }

}
void Serial::recieve()
{
    while(true){
        sp_nonblocking_read(serPort,msg_recieve,25);
        cout<<"Recieve: "<<msg_recieve<<endl;

        if(msg_recieve[0]=='A'||msg_recieve[24]=='E'){
            re_color = msg_recieve[1];
            if(msg_recieve[2]=='Y'){
                if(msg_recieve[3]=='-')
                    re_yaw = -((msg_recieve[4]-'0')*100+(msg_recieve[5]-'0')*10+(msg_recieve[6]-'0')+(msg_recieve[8]-'0')*0.1+(msg_recieve[9]-'0')*0.01);
                else re_yaw = (msg_recieve[4]-'0')*100+(msg_recieve[5]-'0')*10+(msg_recieve[6]-'0')+(msg_recieve[8]-'0')*0.1+(msg_recieve[9]-'0')*0.01;
            }
            if(msg_recieve[10]=='P'){
                if(msg_recieve[11]=='-')
                    re_pitch = -((msg_recieve[12]-'0')*100+(msg_recieve[13]-'0')*10+(msg_recieve[14]-'0')+(msg_recieve[16]-'0')*0.1+(msg_recieve[17]-'0')*0.01);
                else re_pitch = (msg_recieve[12]-'0')*100+(msg_recieve[13]-'0')*10+(msg_recieve[14]-'0')+(msg_recieve[16]-'0')*0.1+(msg_recieve[17]-'0')*0.01;
            }
            if(msg_recieve[18]=='S'){
                re_speed = (msg_recieve[19]-'0')*10+(msg_recieve[20]-'0')+(msg_recieve[22]-'0')*0.1+(msg_recieve[23]-'0')*0.01;
            }
        }
    }
}


