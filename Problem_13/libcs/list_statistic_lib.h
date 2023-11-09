//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_LIST_STATISTIC_LIB_H
#define BTLCTDL_LIST_STATISTIC_LIB_H

#include <iostream>
#include <string>
#include "vector.hpp"
#include "Statistic_lib.h"

class List_Statistic {
private:
    dynamicArray<Statistic> statisticList;
public:
    List_Statistic();
    void add(Statistic Listt);
    void outPut();
};

#endif //BTLCTDL_LIST_STATISTIC_LIB_H
