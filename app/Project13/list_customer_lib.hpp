//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_LIST_CUSTOMER_LIB_H
#define BTLCTDL_LIST_CUSTOMER_LIB_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "customer_lib.hpp"


using namespace std;

class Customer_List {
private:
    vector<Customer> listCustomer;
public:
    void inputFile(string _fileName_kh);
    vector<Customer> get_list_Customer();
};

void Customer_List::inputFile(std::string _fileName_kh) {
    ifstream fileIn;
    fileIn.open(_fileName_kh, ios::in);
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

vector<Customer> Customer_List::get_list_Customer() {
    return listCustomer;
}


#endif //BTLCTDL_LIST_CUSTOMER_LIB_H
