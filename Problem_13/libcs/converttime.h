//
// Created by admin on 03/11/2023.
//

#ifndef BTLCTDL_CONVERTTIME_H
#define BTLCTDL_CONVERTTIME_H

#include<iostream>
#include<cstring>

using namespace std;

class converttime {
private:
    int total_day;
    int day;
    int month;
    int year;
    string date;
    string celandar;
public:
    converttime();
    converttime(int day, int month, int year);
    converttime(string date);
    string convert_date_to_celandar(int total_day);
    int get_day();
    int get_month();
    int get_year();
    int get_total_day();
    string get_date();
};


#endif //BTLCTDL_CONVERTTIME_H
