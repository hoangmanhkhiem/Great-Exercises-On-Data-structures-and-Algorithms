//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_CUSTOMER_LIB_H
#define BTLCTDL_CUSTOMER_LIB_H

#include <iostream>

using namespace std;

class Customer {
private:
    string fullName;
    string numberPhone;
public:
    Customer();
    Customer(string fullName, string numberPhone);
    string get_Name();
    string get_numberPhone();
};

Customer::Customer() {
    fullName = "";
    numberPhone = "";
}

Customer::Customer(string fullName, string numberPhone) {
    this->fullName = fullName;
    this->numberPhone = numberPhone;
}

string Customer::get_Name() {
    return fullName;
}

string Customer::get_numberPhone() {
    return numberPhone;
}


#endif //BTLCTDL_CUSTOMER_LIB_H
