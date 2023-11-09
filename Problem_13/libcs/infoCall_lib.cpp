//
// Created by admin on 04/11/2023.
//

#include "infoCall_lib.h"


infoCall::infoCall() {
    numberPhone = "";
    minutes = 0;
    start_time = "";
    callDate = "";
    location = "";
}
infoCall::infoCall(string numberPhone, int minutes, string start_time,int start_hour, string callDate, string location) {
    this->numberPhone = numberPhone;
    this->minutes = minutes;
    this->start_time = start_time;
    this->start_hour = start_hour;
    this->callDate = callDate;
    this->location = location;
}
string infoCall::get_numberPhone() {
    return numberPhone;
}
int infoCall::get_minutes() {
    return minutes;
}
string infoCall::get_start_time() {
    return start_time;
}
int infoCall::get_start_hour() {
    return start_hour;
}
string infoCall::get_callDate() {
    return callDate;
}
string infoCall::get_location() {
    return location;
}