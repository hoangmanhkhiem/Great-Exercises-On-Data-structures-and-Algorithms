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

Statistic::Statistic() {
    fullName = "";
    numberPhone = "";
    callFee = 0;
    callNumber_NH = 0;
    callNumber_LC = 0;
    callNumber_X = 0;
    callNumber_RX = 0;
}

Statistic::Statistic(string fullName, string numberPhone, int callFee, int callNumber_NH, int callNumber_LC, int callNumber_X, int callNumber_RX) {
    this->fullName = fullName;
    this->numberPhone = numberPhone;
    this->callFee = callFee;
    this->callNumber_NH = callNumber_NH;
    this->callNumber_LC = callNumber_LC;
    this->callNumber_X = callNumber_X;
    this->callNumber_RX = callNumber_RX;
}

string Statistic::get_fullName() {
    return fullName;
}

string Statistic::get_numberPhone() {
    return numberPhone;
}

int Statistic::get_callFee() {
    return callFee;
}

int Statistic::get_callNumber_NH() {
    return callNumber_NH;
}

int Statistic::get_callNumber_LC() {
    return callNumber_LC;
}

int Statistic::get_callNumber_X() {
    return callNumber_X;
}

int Statistic::get_callNumber_RX() {
    return callNumber_RX;
}



#endif //BTLCTDL_STATISTIC_LIB_H
