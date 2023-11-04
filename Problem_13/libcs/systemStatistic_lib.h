//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_SYSTEMSTATISTIC_LIB_H
#define BTLCTDL_SYSTEMSTATISTIC_LIB_H

#include <iostream>
#include <vector>
#include "customer_lib.h"
#include "infoCall_lib.h"
#include "Statistic_lib.h"
#include "list_customer_lib.h"
#include "list_called_lib.h"
#include "list_statistic_lib.h"
#include "converttime.h"

class systemStatistics{
private:
    Customer_List _listCustomer;
    List_Called _listCalled;
    List_Statistic _listStatistic;
public:
    systemStatistics();
    void tinhTien();
    void xuat();
};


#endif //BTLCTDL_SYSTEMSTATISTIC_LIB_H
