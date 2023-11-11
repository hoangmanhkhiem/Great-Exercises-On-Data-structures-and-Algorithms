cmake_minimum_required(VERSION 3.26)
project(Problem29)

set(CMAKE_CXX_STANDARD 17)

add_executable(Problem29 main.cpp
        HuffmanTree.h
        priorityqueue.hpp)
