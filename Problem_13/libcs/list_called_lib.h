//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_LIST_CALLED_LIB_H
#define BTLCTDL_LIST_CALLED_LIB_H

#include <vector>
#include "infoCall_lib.h"


class List_Called {
private:
    vector<infoCall> callList;
public:
    List_Called();
    void inputFile();
    void outPut();
    vector<infoCall> get_List_Called();
};


#endif //BTLCTDL_LIST_CALLED_LIB_H
