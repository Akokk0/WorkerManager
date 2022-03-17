//
// Created by Akokko的Mac on 2022/3/14.
//

#ifndef WOKERMANAGER_WORKERMANAGER_H

#include <iostream>

using namespace std;

#define WOKERMANAGER_WORKERMANAGER_H


class WorkerManager {

private:

    int choice;

public:

    WorkerManager();

    void showMenu();

    void startManager();

    void exitSystem();

    ~WorkerManager();

};


#endif //WOKERMANAGER_WORKERMANAGER_H
