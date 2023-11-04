cmake_minimum_required(VERSION 3.26)
project(BTLCTDL)

set(CMAKE_CXX_STANDARD 17)

add_executable(BTLCTDL main.cpp
        libcs/converttime.cpp
        libcs/converttime.h
        libcs/customer_lib.cpp
        libcs/customer_lib.h
        libcs/infoCall_lib.cpp
        libcs/infoCall_lib.h
        libcs/Statistic_lib.cpp
        libcs/Statistic_lib.h
        libcs/list_customer_lib.cpp
        libcs/list_customer_lib.h
        libcs/list_called_lib.cpp
        libcs/list_called_lib.h
        libcs/list_statistic_lib.cpp
        libcs/list_statistic_lib.h
        libcs/systemStatistic_lib.cpp
        libcs/systemStatistic_lib.h
        libcs/setup.cpp
        libcs/setup.h
)
