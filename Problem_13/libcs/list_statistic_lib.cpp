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

void List_Statistic::outPut(){
    for (int i = 0; i < statisticList.size(); i++) {
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

void List_Statistic::outPutFile() {
    ofstream fileOut;
    fileOut.open("../ketqua.txt", ios::out);
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