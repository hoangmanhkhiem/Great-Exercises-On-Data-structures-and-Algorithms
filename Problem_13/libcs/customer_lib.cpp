//
// Created by admin on 04/11/2023.
//

#include "customer_lib.h"

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
