#include <iostream>
#include "WorkerManager.h"

#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

using namespace std;

int main() {

    //测试代码
    Worker *worker = NULL;
    worker = new Employee(1, "小李", 32);
    worker->showPersonalInfo();
    delete worker;

    worker = new Manager(2, "大李", 12);
    worker->showPersonalInfo();
    delete worker;

    worker = new Boss(3, "王李", 75);
    worker->showPersonalInfo();
    delete worker;

    /*WorkerManager wm;

    wm.startManager();*/

    return 0;
}
