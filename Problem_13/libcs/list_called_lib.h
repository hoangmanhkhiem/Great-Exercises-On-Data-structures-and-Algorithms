//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_LIST_CALLED_LIB_H
#define BTLCTDL_LIST_CALLED_LIB_H

#include "vector.hpp"
#include "infoCall_lib.h"
#include <fstream>
#include <string>
#include <sstream>



class List_Called {
private:
    dynamicArray<infoCall> callList;
public:
    List_Called();
    void inputFile();
    void outPut();
    dynamicArray<infoCall> get_List_Called();
};


#endif //BTLCTDL_LIST_CALLED_LIB_H
