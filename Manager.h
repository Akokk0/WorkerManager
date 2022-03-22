//
// Created by Akokko的Mac on 2022/3/16.
//

#ifndef WOKERMANAGER_MANAGER_H

#include "Worker.h"
#include <iostream>
#include <string>

using namespace std;

#define WOKERMANAGER_MANAGER_H

class Manager : public  Worker {

public:

    Manager();
    Manager(int id, string name, int deptId);

    /*void showPersonalInfo();*/

    string getDeptName();
    string getDuty();

    ~Manager();

};

#endif //WOKERMANAGER_MANAGER_H
