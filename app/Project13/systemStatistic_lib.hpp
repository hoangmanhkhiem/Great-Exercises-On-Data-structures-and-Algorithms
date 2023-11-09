//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_SYSTEMSTATISTIC_LIB_H
#define BTLCTDL_SYSTEMSTATISTIC_LIB_H

#include <iostream>
#include <vector>
#include "list_customer_lib.hpp"
#include "list_called_lib.hpp"
#include "list_statistic_lib.hpp"
#include "converttime.hpp"

class systemStatistics{
private:
    Customer_List _listCustomer;
    List_Called _listCalled;
    List_Statistic _listStatistic;
    string _fileName_kh;
    string _fileName_cg;
    string _fileName_kq;
public:
    void set_fileName_kh(string fileName_kh) {
        this->_fileName_kh = std::move(fileName_kh);
    }

    void set_fileName_cg(string fileName_cg) {
        this->_fileName_cg = std::move(fileName_cg);
    }

    void set_fileName_kq(string fileName_kq) {
        this->_fileName_kq = std::move(fileName_kq);
    }

    void set() {
        _listCustomer.inputFile(_fileName_kh);
        _listCalled.inputFile(_fileName_cg);
    }

    bool checking_stt(string str1, string str2){
        if (str1.length() != str2.length()) return false;
        for (int i = 0; i < str1.length(); i++){
            if (str1[i] != str2[i]) return false;
        }
        return true;
    }

    void tinhTien() {
        converttime timee;
        vector<Customer> listCustomerinFile = this->_listCustomer.get_list_Customer();
        vector<infoCall> listCalledinFile = this->_listCalled.get_List_Called();
        for (int i = 0; i < listCustomerinFile.size(); i++) {
            int total_FEE = 0;
            int _numberCall_NH = 0;
            int _numberCall_LC = 0;
            int _numberCall_X = 0;
            int _numberCall_RX = 0;
            int factor_location = 1;
            for (int j = 0; j < listCalledinFile.size(); j++){
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
                    converttime call_Date_st = converttime(listCalledinFile[j].get_callDate());
                    string thu_may = call_Date_st.convert_date_to_celandar();
                    if ((listCalledinFile[j].get_start_hour() >= 23 && listCalledinFile[j].get_start_hour() <= 5)
                        || thu_may == "Saturday" ||
                        thu_may == "Sunday") {
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

    int total_minute_customer_search(string phone_NUM){
        vector<Customer> listCustomerinFile = this->_listCustomer.get_list_Customer();
        vector<infoCall> listCalledinFile = this->_listCalled.get_List_Called();
        int total_minute = 0;
        for (int i= 0; i < listCustomerinFile.size(); i++){
            string num1 = listCustomerinFile[i].get_numberPhone();
            num1.erase(0, 1);
            if(num1 == phone_NUM) {
                for (int j = 0; j < listCalledinFile.size(); j++) {
                    string num2 = listCalledinFile[j].get_numberPhone();
                    if (checking_stt(phone_NUM, num2)) {
                        total_minute += listCalledinFile[j].get_minutes();
                    }
                }
                return total_minute;
            }
        }
        return -1;
    }

    string searching_name_phonenumber(string nameChecking){
        vector<Customer> listCustomerinFile = this->_listCustomer.get_list_Customer();
        vector<infoCall> listCalledinFile = this->_listCalled.get_List_Called();
        for (int i= 0; i < listCustomerinFile.size(); i++){
            string num1 = listCustomerinFile[i].get_numberPhone();
            num1.erase(0, 1);
            if(num1 == nameChecking) {
                return listCustomerinFile[i].get_Name();
            }
        }
        return "Not found";
    }

    void xuat(){

//        printf("|%-30s|%-15s|%-15s|%-10s|%-10s|%-10s|%-10s|\n", "Full Name", "NumberPhone", "Total_FEE", "number_NH",
//               "number_LC", "number_X", "number_RX");
//        printf("|------------------------------|---------------|---------------|----------|----------|----------|----------|\n");
//        _listStatistic.outPut();
        _listStatistic.outPutFile(_fileName_kq);
    }

    long get_total_fee_by_sdt(string phone_NUM) {
        vector<Customer> listCustomerinFile = this->_listCustomer.get_list_Customer();
        vector<infoCall> listCalledinFile = this->_listCalled.get_List_Called();
        for (int i= 0; i < listCustomerinFile.size(); i++){
            string num1 = listCustomerinFile[i].get_numberPhone();
            num1.erase(0, 1);
            int total_FEE = 0;
            int factor_location = 1;
            if(num1 == phone_NUM) {
                for (int j = 0; j < listCalledinFile.size(); j++) {
                    string num2 = listCalledinFile[j].get_numberPhone();
                    if (checking_stt(phone_NUM, num2)) {
                        string location = listCalledinFile[j].get_location();
                        location.erase(0, 1); // erase the backspace in location
                        if (checking_stt(location, "NH")) {
                            factor_location = 1;
                        }
                        else if (checking_stt(location, "LC")){
                            factor_location = 2;
                        }
                        else if (checking_stt(location, "X")){
                            factor_location = 3;
                        }
                        else if (checking_stt(location, "RX")){
                            factor_location = 4;
                        }
                        int minute = listCalledinFile[j].get_minutes();
                        converttime call_Date_st = converttime(listCalledinFile[j].get_callDate());
                        string thu_may = call_Date_st.convert_date_to_celandar();
                        if ((listCalledinFile[j].get_start_hour() >= 23 && listCalledinFile[j].get_start_hour() <= 5)
                            || thu_may == "Saturday" ||
                            thu_may == "Sunday") {
                            total_FEE += 770 * minute * factor_location;
                        }
                        else total_FEE += 1100 * minute * factor_location;
                    }
                }
                return total_FEE;
            }
        }
        return -1;
    }
};


#endif //BTLCTDL_SYSTEMSTATISTIC_LIB_H
