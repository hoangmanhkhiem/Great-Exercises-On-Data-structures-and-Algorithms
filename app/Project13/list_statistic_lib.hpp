//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_LIST_STATISTIC_LIB_H
#define BTLCTDL_LIST_STATISTIC_LIB_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Statistic_lib.hpp"
#include <fstream>

class List_Statistic {
private:
    vector<Statistic> statisticList;
public:
    List_Statistic();
    void add(Statistic Listt);
    void outPutFile(string _fileName_kq);
};

List_Statistic::List_Statistic() {
    statisticList.clear();
}

void List_Statistic::add(Statistic Listt) {
    statisticList.push_back(Listt);
}

void List_Statistic::outPutFile(string _fileName_kq) {
    ofstream fileOut;
    fileOut.open(_fileName_kq, ios::out);
    if (fileOut.is_open()) {
        fileOut << std::left
                << "|" << std::setw(30) << "Full Name"
                << "|" << std::setw(15) << "NumberPhone"
                << "|" << std::setw(15) << "Total_FEE"
                << "|" << std::setw(10) << "number_NH"
                << "|" << std::setw(10) << "number_LC"
                << "|" << std::setw(10) << "number_X"
                << "|" << std::setw(10) << "number_RX"
                << "|\n";
        fileOut << "|------------------------------|---------------|---------------|----------|----------|----------|----------|\n";
        for (int i = 0; i < statisticList.size(); i++) {
            fileOut << "|" << std::setw(30) << std::left << statisticList[i].get_fullName();
            fileOut << "|" << std::setw(15) << std::left << statisticList[i].get_numberPhone().substr(1, 10);
            fileOut << "|" << std::setw(15) << std::left << statisticList[i].get_callFee();
            fileOut << "|" << std::setw(10) << std::left << statisticList[i].get_callNumber_NH();
            fileOut << "|" << std::setw(10) << std::left << statisticList[i].get_callNumber_LC();
            fileOut << "|" << std::setw(10) << std::left << statisticList[i].get_callNumber_X();
            fileOut << "|" << std::setw(10) << std::left << statisticList[i].get_callNumber_RX();
            fileOut << "|\n";

            fileOut << "|------------------------------|---------------|---------------|----------|----------|----------|----------|\n";
        }
    }
    fileOut.close();
}

#endif //BTLCTDL_LIST_STATISTIC_LIB_H
