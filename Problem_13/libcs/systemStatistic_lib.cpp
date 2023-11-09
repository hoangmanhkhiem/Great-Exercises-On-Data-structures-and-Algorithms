//
// Created by admin on 04/11/2023.
//

#include "systemStatistic_lib.h"

using namespace std;

systemStatistics::systemStatistics() {
    _listCustomer.inputFile();
    _listCalled.inputFile();
}

bool checking_stt(string str1, string str2){
    if (str1.length() != str2.length()) return false;
    for (int i = 0; i < str1.length(); i++){
        if (str1[i] != str2[i]) return false;
    }
    return true;
}

void systemStatistics::tinhTien() {
    dynamicArray<Customer> listCustomerinFile = this->_listCustomer.get_list_Customer();
    dynamicArray<infoCall> listCalledinFile = this->_listCalled.get_List_Called();
    for (int i = 0; i < listCustomerinFile.get_size(); i++) {
        int total_FEE = 0;
        int _numberCall_NH = 0;
        int _numberCall_LC = 0;
        int _numberCall_X = 0;
        int _numberCall_RX = 0;
        int factor_location = 1;
        for (int j = 0; j < listCalledinFile.get_size(); j++){
            string num1 = listCustomerinFile[i].get_numberPhone();
            num1.erase(0, 1); // erase the backspace in num1
            string num2 = listCalledinFile[j].get_numberPhone();
            if (checking_stt(num1, num2)) {
                string location = listCalledinFile[j].get_location();
                location.erase(0, 1); // erase the backspace in location
                if (checking_stt(location, "NH")) {
                    _numberCall_NH++;
                    factor_location = 1;
                }
                else if (checking_stt(location, "LC")){
                    _numberCall_LC++;
                    factor_location = 2;
                }
                else if (checking_stt(location, "X")){
                    _numberCall_X++;
                    factor_location = 3;
                }
                else if (checking_stt(location, "RX")){
                    _numberCall_RX++;
                    factor_location = 4;
                }
                int minute = listCalledinFile[j].get_minutes();
                if ((listCalledinFile[j].get_start_hour() >= 23 && listCalledinFile[j].get_start_hour() <= 5)
                    || listCalledinFile[j].get_callDate() == "Saturday" ||
                    listCalledinFile[j].get_callDate() == "Sunday") {
                    total_FEE += 770 * minute * factor_location;
                }
                else total_FEE += 1100 * minute * factor_location;
            }
        }
        Statistic ketQua(listCustomerinFile[i].get_Name(), listCustomerinFile[i].get_numberPhone(), total_FEE,
                         _numberCall_NH, _numberCall_LC, _numberCall_X, _numberCall_RX);
        _listStatistic.add(ketQua);
    }
}

void systemStatistics::xuat() {
    printf("|%-30s|%-15s|%-15s|%-10s|%-10s|%-10s|%-10s|\n", "Full Name", "NumberPhone", "Total_FEE", "number_NH",
           "number_LC", "number_X", "number_RX");
    printf("|------------------------------|---------------|---------------|----------|----------|----------|----------|\n");
    _listStatistic.outPut();
}

