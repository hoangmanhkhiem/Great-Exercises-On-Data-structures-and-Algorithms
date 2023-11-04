//
// Created by admin on 03/11/2023.
//

#include <sstream>
#include "converttime.h"

using namespace std;

// Năm nhuận là năm chia hết cho 4 nhưng không chia hết cho 100 hoặc chia hết cho 400

int Caculate_Day(int day,int month,int year){
    int total_day = 0;
    for (int i = 1; i < month; i++) {
        if (i == 2) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    total_day += 29;
                } else {
                    total_day += 28;
                }
            } else {
                if (year % 4 == 0) {
                    total_day += 29;
                } else {
                    total_day += 28;
                }
            }
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            total_day += 30;
        } else {
            total_day += 31;
        }
    }
    total_day += year/400;
    total_day += year/4;
    total_day -= year/100;
    total_day += (year-1)*365;
    total_day += day-1;
    return total_day;
}

string converttime::convert_date_to_celandar(int total_day){
    int day = total_day%7;
    string celandars[7] = {"Monday","Tuesday","Wednesday","Thursday"
                           ,"Friday","Saturday","Sunday"}; // 0 1 2 3 4 5 6
    return celandars[day];
}

converttime::converttime() {
    day = 0;
    month = 0;
    year = 0;
    date = "01/01/0001";
}

converttime::converttime(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
    date = "(" + to_string(day) + "/" + to_string(month) + "/" + to_string(year) + ")";
    total_day = Caculate_Day(day,month,year);
}

converttime::converttime(string date) {
    this->date = date;
    stringstream ss(date);
    string _day, _month, _year;
    getline(ss, _day, '/');
    getline(ss, _month, '/');
    getline(ss, _year, '/');
    day = stoi(_day);
    month = stoi(_month);
    year = stoi(_year);
    total_day = Caculate_Day(day,month,year);
}

int converttime::get_day() {
    return day;
}

int converttime::get_month() {
    return month;
}

int converttime::get_year() {
    return year;
}

string converttime::get_date() {
    return date;
}

int converttime::get_total_day() {
    return total_day;
}