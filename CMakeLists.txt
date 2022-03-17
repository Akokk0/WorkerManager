cmake_minimum_required(VERSION 3.21)
project(WokerManager)

set(CMAKE_CXX_STANDARD 14)

add_executable(WokerManager main.cpp WorkerManager.cpp WorkerManager.h Worker.h Employee.cpp Employee.h Manager.cpp Manager.h Boss.cpp Boss.h)
