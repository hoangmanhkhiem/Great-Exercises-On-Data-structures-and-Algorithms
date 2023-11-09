#include<iostream>
#include<fstream>
#include<string>
#include "systemStatistic_lib.hpp"

int main(){
    systemStatistics sys;
    sys.set_fileName_kh("D:/PythonProject/Project13/data/khachhang.txt");
    sys.set_fileName_cg("D:/PythonProject/Project13/data/cuocgoi.txt");
    sys.set_fileName_kq("");
    int option = 1;
    string nameChecking = "";
    if(option == 1){
        sys.set();
        sys.tinhTien();
        sys.xuat();
    }
    else if(option ==2){
        sys.set();
        ofstream fileOut;
        fileOut.open("log_time.txt", ios::out);
        if (fileOut.is_open()){
            fileOut << sys.searching_name_phonenumber(nameChecking) << "\n";
            fileOut << sys.total_minute_customer_search(nameChecking);
        }
    }
    else if(option == 3){
        sys.set();
        ofstream fileOut;
        fileOut.open("log_cuoc.txt", ios::out);
        if (fileOut.is_open()){
            fileOut << sys.searching_name_phonenumber(nameChecking) << "\n";
            fileOut << sys.get_total_fee_by_sdt(nameChecking);
        }
    }
}