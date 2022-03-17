//
// Created by Akokko的Mac on 2022/3/17.
//

#include "Boss.h"

Boss::Boss() {}
Boss::Boss(int id, string name, int deptId) : Worker(id, name, deptId) {}

string Boss::getDeptName() {

    return "资本";
}

string Boss::getDuty() {

    return "当资本家";

}

Boss::~Boss() {}
