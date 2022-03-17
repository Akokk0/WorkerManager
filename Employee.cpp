//
// Created by Akokko的Mac on 2022/3/15.
//

#include "Employee.h"

Employee::Employee() {}
Employee::Employee(int id, string name, int deptId) : Worker(id, name, deptId) {}

/*void Employee::showPersonalInfo() {

    cout << "职工编号：" << m_Id
    << "\t职工姓名：" << m_Name
    << "\t岗位编号：" << this->getDeptName()
    << "\t岗位指责：完成经理交给的任务" << endl;

}*/

string Employee::getDeptName() {

    return "员工";

}

string Employee::getDuty() {

    return "完成经理交给的任务";

}

Employee::~Employee() {}