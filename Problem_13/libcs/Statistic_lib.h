//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_STATISTIC_LIB_H
#define BTLCTDL_STATISTIC_LIB_H

#include<iostream>

using namespace std;

class Statistic {
private:
    string fullName;
    string numberPhone;
    int callFee;
    int callNumber_NH;
    int callNumber_LC;
    int callNumber_X;
    int callNumber_RX;
public:
    Statistic();
    Statistic(string fullName, string numberPhone, int callFee, int callNumber_NH, int callNumber_LC, int callNumber_X, int callNumber_RX);
    string get_fullName();
    string get_numberPhone();
    int get_callFee();
    int get_callNumber_NH();
    int get_callNumber_LC();
    int get_callNumber_X();
    int get_callNumber_RX();
};


#endif //BTLCTDL_STATISTIC_LIB_H
