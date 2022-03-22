//
// Created by Akokko的Mac on 2022/3/14.
//

#ifndef WOKERMANAGER_WORKERMANAGER_H

#include <unistd.h>
#include <iostream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include <fstream>
#define FILENAME "empFile.txt"

using namespace std;

#define WOKERMANAGER_WORKERMANAGER_H


class WorkerManager {

private:

    //选择数
    int choice;

    //员工数组指针
    Worker ** m_EmpArray = NULL;

    //员工人数
    int m_EmpNum;

    //文件不存在变量
    bool m_fileIsNotExit;

public:

    WorkerManager();

    void showMenu();

    void startManager();

    void addEmp();

    void saveFile();

    void exitSystem();

    ~WorkerManager();

};


#endif //WOKERMANAGER_WORKERMANAGER_H
