//
// Created by Akokko的Mac on 2022/3/15.
//

#ifndef WOKERMANAGER_EMPLOYEE_H

#include "Worker.h"
#include <iostream>
#include <string>

using namespace std;

#define WOKERMANAGER_EMPLOYEE_H


class Employee : public Worker {

public:

    Employee();

    Employee(int id, string name, int deptId);

/*    void showPersonalInfo();*/

    string getDeptName();
    string getDuty();

    ~Employee();

};

#endif //WOKERMANAGER_EMPLOYEE_H
