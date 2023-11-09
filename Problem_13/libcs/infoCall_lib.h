//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_INFOCALL_LIB_H
#define BTLCTDL_INFOCALL_LIB_H

#include<iostream>

using namespace std;

class infoCall {
private:
    string numberPhone;
    int minutes;
    string start_time;
    int start_hour;
    string callDate;
    string location;
public:
    infoCall();
    infoCall(string numberPhone, int minutes, string start_time,int start_hour, string callDate, string location);
    string get_numberPhone();
    int get_minutes();
    string get_start_time();
    int get_start_hour();
    string get_callDate();
    string get_location();
};


#endif //BTLCTDL_INFOCALL_LIB_H
