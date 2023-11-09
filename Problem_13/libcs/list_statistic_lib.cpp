//
// Created by admin on 04/11/2023.
//

#include "list_statistic_lib.h"

List_Statistic::List_Statistic() {
    statisticList.clear();
}

void List_Statistic::add(Statistic Listt) {
    statisticList.push_back(Listt);
}

void List_Statistic::outPut() {
    for (int i = 0; i < statisticList.get_size(); i++) {
        printf("|%-30s|%-15s|%-15d|%-10d|%-10d|%-10d|%-10d|\n",
               statisticList[i].get_fullName().c_str(),
               statisticList[i].get_numberPhone().substr(1, 10).c_str(),
               statisticList[i].get_callFee(),
               statisticList[i].get_callNumber_NH(),
               statisticList[i].get_callNumber_LC(),
               statisticList[i].get_callNumber_X(),
               statisticList[i].get_callNumber_RX());
        printf("|------------------------------|---------------|---------------|----------|----------|----------|----------|\n");
    }
}