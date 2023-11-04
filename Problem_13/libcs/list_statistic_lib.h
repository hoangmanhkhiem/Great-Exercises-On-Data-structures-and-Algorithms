//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_LIST_STATISTIC_LIB_H
#define BTLCTDL_LIST_STATISTIC_LIB_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Statistic_lib.h"
#include <fstream>

class List_Statistic {
private:
    vector<Statistic> statisticList;
public:
    List_Statistic();
    void add(Statistic Listt);
    void outPut();
    void outPutFile();
};

#endif //BTLCTDL_LIST_STATISTIC_LIB_H
