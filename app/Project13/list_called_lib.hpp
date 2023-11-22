//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_LIST_CALLED_LIB_H
#define BTLCTDL_LIST_CALLED_LIB_H

#include <vector>
#include "infoCall_lib.hpp"


class List_Called {
private:
    vector<infoCall> callList;
public:
    List_Called();
    void inputFile(string _fileName_cg);
    vector<infoCall> get_List_Called();
};

List_Called::List_Called() {
    callList.clear();
}

void List_Called::inputFile(string _fileName_cg) {
    ifstream fileIn;
    fileIn.open(_fileName_cg, ios::in);
    if (fileIn.is_open()) {
        string line;
        while (!fileIn.eof()) {
            getline(fileIn, line);
            if (line == "") {
                break;
            }
            stringstream ss(line);
            string nPhone;
            string minutes;
            string timeStart;
            int hourStart;
            string callDate;
            string location;
            getline(ss, nPhone, ';');
            getline(ss, minutes, ';');
            getline(ss, timeStart, ';');
            getline(ss, callDate, ';');
            getline(ss, location, ';');
            hourStart = stoi(timeStart.substr(0,2));
            infoCall iCall(nPhone, stoi(minutes), timeStart,hourStart, callDate, location);
            callList.push_back(iCall);
        }
    }
    fileIn.close();
}

vector<infoCall> List_Called::get_List_Called() {
    return callList;
}


#endif //BTLCTDL_LIST_CALLED_LIB_H
