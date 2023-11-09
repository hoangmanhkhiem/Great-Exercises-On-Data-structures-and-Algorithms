//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_LIST_CUSTOMER_LIB_H
#define BTLCTDL_LIST_CUSTOMER_LIB_H

#include <iostream>
#include "vector.hpp"
#include "customer_lib.h"


using namespace std;

class Customer_List {
private:
    dynamicArray<Customer> listCustomer;
public:

//    Customer_List();
    void inputFile();
    void outPut();
    dynamicArray<Customer> get_list_Customer();
};


#endif //BTLCTDL_LIST_CUSTOMER_LIB_H
