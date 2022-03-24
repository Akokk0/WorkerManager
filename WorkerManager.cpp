//
// Created by Akokko的Mac on 2022/3/14.
//

#include "WorkerManager.h"

WorkerManager::WorkerManager() {

    //创建读文件对象
    ifstream ifs;
    //打开文件
    ifs.open(FILENAME, ios::in);

    //文件不存在
    if ( !ifs.is_open() ) {

        cout << "测试输出，文件不存在" << endl;

        //文件不存在变量设置为真
        m_fileIsNotExit = true;

        //员工数组设置为空
        m_EmpArray = NULL;
        //员工数设置为0
        m_EmpNum = 0;

        //关闭文件，退出下面操作
        ifs.close();
        return;

    }

    //文件数据为空
    char ch;
    ifs >> ch;
    if ( ifs.eof() ) {

        cout << "测试输出，文件为空" << endl;

        //文件不存在变量设置为真
        m_fileIsNotExit = true;

        //员工数组设置为空
        m_EmpArray = NULL;
        //员工数设置为0
        m_EmpNum = 0;

        //关闭文件，退出下面操作
        ifs.close();
        return;

    }

    //文件有数据，统计人数
    int empNum = getEmpNum(ifs);
    cout << "当前员工数为：" << empNum << endl;

    m_EmpNum = empNum;

}

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

                addEmp();

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

void WorkerManager::addEmp() {

    int addNum = 0;

    cout << "请输入新增员工数" << endl;
    cin >> addNum;

    if (addNum > 0) {

        //计算新空间大小
        int newSize = m_EmpNum + addNum;

        //开辟新空间
        Worker ** newSpace = new Worker * [newSize];
        
        //将原储存空间下数据迁移
        if (m_EmpArray != NULL) {

            for (int i = 0; i < m_EmpNum; ++i) {

                newSpace[i] = m_EmpArray[i];

            }

        }

        //添加新员工
        for (int i = 0; i < addNum; ++i) {

            int id = 0;
            string name;
            int dSelect;

            cout << "请输入第" << i + 1 << "名员工的编号" << endl;
            cin >> id;

            cout << "请输入第" << i + 1 << "名员工的姓名" << endl;
            cin >> name;

            cout << "请选择第" << i + 1 << "名员工的职位" << endl;
            cout << "1、普通员工" << endl;
            cout << "2、公司经理" << endl;
            cout << "3、资本家" << endl;
            cin >> dSelect;

            Worker * newEmployee = NULL;

            switch (dSelect) {
                case 1:
                    newEmployee = new Employee(id, name, 1);
                    break;
                case 2:
                    newEmployee = new Employee(id, name, 2);
                    break;
                case 3:
                    newEmployee = new Employee(id, name, 3);
                    break;
                default:
                    cout << "您的输入有误" << endl;
                    break;
            }

            newSpace[m_EmpNum + i] = newEmployee;

        }

        //释放原来旧的空间
        if (m_EmpArray != NULL) {

            delete[] m_EmpArray;

        }

        //将新空间的值赋给员工数组;
        m_EmpArray = newSpace;

        //增加员工数
        m_EmpNum += addNum;

        //保存数据到文件
        saveFile();

        //设置文件为非空
        m_fileIsNotExit = false;

        //输出提示添加成功
        cout << addNum << "名员工添加成功" << endl;

        system("clear");

    } else {

        cout << "您的输入有误" << endl;

    }

}

void WorkerManager::saveFile() {
    
    ofstream ofs;
    
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < m_EmpNum; ++i) {

        ofs << m_EmpArray[i]->m_Id << " "
            << m_EmpArray[i]->m_Name << " "
            << m_EmpArray[i]->m_DeptId << " " << endl;

    }

    ofs.close();
    
}

int WorkerManager::getEmpNum(ifstream &ifs) {

    string temporary;

    int empNum = 0;

    while (getline(ifs, temporary)) {

        empNum++;

    }

    return empNum;

}

void WorkerManager::exitSystem() {

    cout << "欢迎下次使用" << endl;
    exit(0);

}

WorkerManager::~WorkerManager() {

    if (m_EmpArray != NULL) {

        delete[] m_EmpArray;
        m_EmpArray = NULL;

    }

}