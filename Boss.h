//
// Created by Akokko的Mac on 2022/3/17.
//

#ifndef WOKERMANAGER_BOSS_H

#include "Worker.h"
#include <iostream>
#include <string>

using namespace std;

#define WOKERMANAGER_BOSS_H


class Boss : public Worker {

public:

    Boss();
    Boss(int id, string name, int deptId);

    /*void showPersonalInfo();*/

    string getDeptName();
    string getDuty();

    ~Boss();

};


#endif //WOKERMANAGER_BOSS_H
