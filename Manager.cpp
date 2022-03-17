//
// Created by Akokko的Mac on 2022/3/16.
//

#include "Manager.h"

Manager::Manager() {}
Manager::Manager(int id, string name, int deptId) : Worker(id, name, deptId) {}

/*void Manager::showPersonalInfo() {

    cout << "职工编号：" << m_Id
         << "\t职工姓名：" << m_Name
         << "\t岗位编号：" << this->getDeptName()
         << "\t岗位指责：完成经理交给的任务" << endl;

}*/

string Manager::getDeptName() {

    return "经理";

}

string Manager::getDuty() {

    return "完成老板交给的任务，并下发给员工";

}

Manager::~Manager() {}