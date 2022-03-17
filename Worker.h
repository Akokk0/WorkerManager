//
// Created by Akokko的Mac on 2022/3/15.
//

#ifndef WOKERMANAGER_WORKER_H

#include <iostream>
#include <string>

using namespace std;

#define WOKERMANAGER_WORKER_H


class Worker {

public:

    int m_Id;
    string m_Name;
    int m_DeptId;

public:

    Worker() {}
    Worker(int id, string name, int deptId) {

        m_Id = id;
        m_Name = name;
        m_DeptId = deptId;

    }

    virtual void showPersonalInfo() {

        cout << "职工编号：" << m_Id
             << "\t职工姓名：" << m_Name
             << "\t岗位编号：" << getDeptName()
             << "\t岗位指责：" << getDuty() << endl;

    };

    virtual string getDeptName() = 0;
    virtual string getDuty() = 0;

    virtual ~Worker() {};

};


#endif //WOKERMANAGER_WORKER_H
