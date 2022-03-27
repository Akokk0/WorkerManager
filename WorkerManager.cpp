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
    //关闭文件输入流
    ifs.close();

    //将文件存在表示设置为假
    m_fileIsNotExit = false;

    //输出提示信息
    cout << "当前员工数为：" << empNum << endl;

    //更新员工数
    m_EmpNum = empNum;

    //初始化员工
    initEmp();

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
                showEmp();
                break;
            case 3:
                delEmp();
                break;
            case 4:
                modifyEmp();
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

void WorkerManager::initEmp() {

    cout << "正在将员工信息写入内存" << endl;

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if ( !ifs.is_open() ) {

        cout << "打开文件失败！" << endl;
        return;

    }

    int id, deptId, index = 0;
    string name;

    //初始化员工数组
    m_EmpArray = new Worker * [m_EmpNum];

    Worker *worker = NULL;

    while (ifs >> id && ifs >> name && ifs >> deptId) {

        if (deptId == 1) {
            m_EmpArray[index] = new Employee(id, name, deptId);
        }
        if (deptId == 2) {
            m_EmpArray[index] = new Manager(id, name, deptId);
        }
        if (deptId == 3) {
            m_EmpArray[index] = new Boss(id, name, deptId);
        }

        /*if (deptId == 1) {
            worker = new Employee(id, name, deptId);
        }
        if (deptId == 2) {
            worker = new Manager(id, name, deptId);
        }
        if (deptId == 3) {
            worker = new Boss(id, name, deptId);
        }*/

        //m_EmpArray[index] = worker;

        index++;

    }

    ifs.close();

    cout << "员工信息全部写入内存" << endl;

    for (int i = 0; i < m_EmpNum; ++i) {

        /*cout << "员工编号：" << m_EmpArray[i]->m_Id << " "
             << "员工姓名：" << m_EmpArray[i]->m_Name << " "
             << "部门编号：" << m_EmpArray[i]->m_DeptId << endl;*/

        m_EmpArray[i]->showPersonalInfo();

    }

}

void WorkerManager::showEmp() {

    if (m_fileIsNotExit) {

        cout << "文件不存在或为空" << endl;
        return;

    }

    for (int i = 0; i < m_EmpNum; ++i) {

        m_EmpArray[i]->showPersonalInfo();

    }

}

int WorkerManager::empIsExist(int id) {

    for (int i = 0; i < m_EmpNum; ++i) {

        //找到符合条件的成员
        if (m_EmpArray[i]->m_Id == id) {

            return i;

        }

    }

    //没有找到符合条件的成员
    return -1;

}

void WorkerManager::delEmp() {

    if (m_fileIsNotExit) {

        cout << "文件不存在或为空" << endl;
        return;

    }

    cout << "请输入您要删除的员工ID" << endl;

    int num;
    cin >> num;
    if ( (num = empIsExist(num)) == -1) {

        cout << "删除失败，员工不存在！" << endl;

    }

    delete m_EmpArray[num];

    for (int i = num; i < m_EmpNum; ++i) {

        if (num == m_EmpNum - 1) {

            m_EmpArray[i] = NULL;
            goto end;

        }

        m_EmpArray[i] = m_EmpArray[i + 1];

    }
    
    end:

    m_EmpNum--;

    saveFile();

    cout << "删除成功" << endl;

}

void WorkerManager::modifyEmp() {

    //判断文件是否存在
    if (m_fileIsNotExit) {

        cout << "文件不存在或文件为空" << endl;
        return;

    }

    cout << "请输入要修改的员工编号" << endl;
    int id;
    cin >> id;

    if ( (id = empIsExist(id)) == -1 ) {

        cout << "该员工不存在" << endl;
        return;

    }

    int newId = 0;
    string name;
    int dSelect;

    cout << "请输入新的员工编号" << endl;
    cin >> newId;

    cout << "请输入新的员工姓名" << endl;
    cin >> name;

    cout << "请选择新的员工职位" << endl;
    cout << "1、普通员工" << endl;
    cout << "2、公司经理" << endl;
    cout << "3、资本家" << endl;
    cin >> dSelect;

    Worker * newEmployee = NULL;

    switch (dSelect) {
        case 1:
            newEmployee = new Employee(newId, name, 1);
            break;
        case 2:
            newEmployee = new Employee(newId, name, 2);
            break;
        case 3:
            newEmployee = new Employee(newId, name, 3);
            break;
        default:
            cout << "您的输入有误" << endl;
            break;
    }

    //将新员工添加到员工数组中
    m_EmpArray[id] = newEmployee;

    //更新文件
    saveFile();

    cout << "员工修改完毕" << endl;

}

WorkerManager::~WorkerManager() {

    if (m_EmpArray != NULL) {

        delete[] m_EmpArray;
        m_EmpArray = NULL;

    }

}