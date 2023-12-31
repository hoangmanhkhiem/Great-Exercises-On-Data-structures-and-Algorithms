//
// Created by admin on 04/11/2023.
//

#include "list_customer_lib.h"
#include <fstream>
#include <sstream>
#include <iostream>


void Customer_List::inputFile() {
    ifstream fileIn;
    fileIn.open("../khachhang.txt", ios::in);
    if (fileIn.is_open()) {
        string line;
        while (!fileIn.eof()) {
            getline(fileIn, line);
            if (line == "") {
                break;
            }
            stringstream ss(line);
            string fName;
            string nPhone;
            getline(ss, fName, ';');
            getline(ss, nPhone, ';');
            Customer _customer(fName, nPhone);
            listCustomer.push_back(_customer);
        }
    }
    fileIn.close();
}

dynamicArray<Customer> Customer_List::get_list_Customer() {
    return listCustomer;
}

