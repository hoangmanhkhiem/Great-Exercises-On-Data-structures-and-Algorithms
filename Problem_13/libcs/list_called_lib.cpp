//
// Created by admin on 04/11/2023.
//

#include "list_called_lib.h"

using namespace std;

List_Called::List_Called() {
    callList.clear();
}

void List_Called::inputFile() {
    ifstream fileIn;
    fileIn.open("../cuocgoi.txt", ios::in);
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

dynamicArray<infoCall> List_Called::get_List_Called() {
    return callList;
}


