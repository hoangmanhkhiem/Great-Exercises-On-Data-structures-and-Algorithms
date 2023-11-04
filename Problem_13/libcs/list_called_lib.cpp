//
// Created by admin on 04/11/2023.
//

#include "list_called_lib.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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

void List_Called::outPut() {
    for (int i = 0; i < callList.size(); i++) {
        cout << callList[i].get_numberPhone() << " " << callList[i].get_minutes() << " "
             << callList[i].get_start_time() << " " << callList[i].get_callDate() << " "
             << callList[i].get_location() << endl;
    }
}

vector<infoCall> List_Called::get_List_Called() {
    return callList;
}


