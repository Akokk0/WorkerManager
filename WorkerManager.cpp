//
// Created by Akokko的Mac on 2022/3/14.
//

#include "WorkerManager.h"

WorkerManager::WorkerManager() {}

void WorkerManager::showMenu() {

    cout << "***********************************************" << endl;
    cout << "************* 欢迎使用职工管理系统 *************" << endl;
    cout << "**************** 0.退出管理程序 ****************" << endl;
    cout << "**************** 1.增加职工信息 ****************" << endl;
    cout << "**************** 2.显示职工信息 ****************" << endl;
    cout << "**************** 3.删除职工信息 ****************" << endl;
    cout << "**************** 4.修改职工信息 ****************" << endl;
    cout << "**************** 5.查找职工信息 ****************" << endl;
    cout << "**************** 6.按照编号排序 ****************" << endl;
    cout << "**************** 7.清空所有文档 ****************" << endl;
    cout << "***********************************************" << endl;

}

void WorkerManager::startManager() {

    while (true) {

        showMenu();

        cout << "请输入您的选择：" << endl;
        cin >> choice;

        switch (choice) {

            case 0:

                exitSystem();

            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            case 7:

                break;

            default:
                system("clear");
                break;

        }

    }

}

void WorkerManager::exitSystem() {

    cout << "欢迎下次使用" << endl;
    exit(0);

}

WorkerManager::~WorkerManager() {}