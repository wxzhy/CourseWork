//
// Created by Admin on 2023/5/2.
//

#include "StudentManager.h"
#include "Link.h"

void StudentManager::menu() {
    while (true) {
        Display::Head(">>管理模块>>学生管理");
        cout << "     1.查看全部学生" << endl;
        cout << "     2.添加学生" << endl;
        cout << "     3.修改学生" << endl;
        cout << "     4.删除学生" << endl;
        cout << "     5.按学号查询" << endl;
        cout << "     6.按姓名查询" << endl;
        cout << "     7.从文件添加" << endl;
        cout << "     0.返回上级菜单" << endl;
        Display::Tail();
        cout << "请输入：";
        int op;
        cin >> op;
        switch (op) {
            case 1:
                displayAll();
                break;
            case 2:
                add();
                break;
            case 3:
                edit();
                break;
            case 4:
                del();
                break;
            case 5:
                findById();
                break;
            case 6:
                findByName();
                break;
            case 7:
                addFromFile();
                break;
            case 0:
                return;
            default:
                cout << "输入错误！" << endl;

        }
    }
}

void StudentManager::displayAll() {
    print(students);

}

void StudentManager::print(vector<Student> &s) {
    if (s.empty()) {
        cout << "未找到" << endl;
        return;
    }

    cout << "+------------+------------+------------+--------+" << endl;
    cout << "| " << setw(10) << "学号" << " | " << setw(10) << "姓名" << " | "
         << setw(10) << "专业" << " | " << setw(6) << "年级" << " |" << endl;
    cout << "+------------+------------+------------+--------+" << endl;
    int n = 0;
    for (auto &i: s) {
        n++;
        cout << "| " << left << setw(10) << i.getId() << " | " << left << setw(10) << i.getName() << " | " << left
             << setw(10)
             << i.getProf() << " | " << left << setw(6) << i.getGrade() << " |" << endl;
        if (n % 20 == 0) {
            system("pause");
        }
    }

    cout << "+------------+------------+------------+--------+" << endl;
    cout << "共有" << n << "条结果" << endl;
}


void StudentManager::add() {
    Student stu;
    string str;
    cout << "输入学号：";
    cin >> str;
    if (student_link.ifExist(str)) {
        cout << "该学号已存在" << endl;
        return;
    }
    stu.setId(str);
    cout << "输入姓名：";
    cin >> str;
    stu.setName(str);
    cout << "输入性别：";
    cin >> str;
    stu.setSex(str);
    cout << "输入专业：";
    cin >> str;
    stu.setProf(str);
    cout << "输入年级：";
    int grade;
    cin >> grade;
    stu.setGrade(grade);
    students.push_back(stu);
    student_link.sortById();

}

void StudentManager::edit() {
    //findByName();
    cout << "输入要修改的学号：";
    string id;
    cin >> id;
    int num = student_link.getNumById(id);
    if (num == -1) {
        cout << "未找到" << endl;
        return;
    }
    //cout << "原信息：";
    Display::Message("原信息");
    print(students[num]);
    Display::Head(">>管理模块>>学生管理>>修改学生");
    cout << "     1.修改姓名" << endl;
    cout << "     2.修改性别" << endl;
    cout << "     3.修改专业" << endl;
    cout << "     4.修改年级" << endl;
    Display::Tail();
    int op;
    cout << "请输入：";
    cin >> op;

    switch (op) {
        case 1: {
            cout << "输入姓名：";
            string str;
            cin >> str;
            students[num].setName(str);
            break;
        }
        case 2: {
            cout << "输入性别：";
            string str;
            cin >> str;
            students[num].setSex(str);
            break;
        }
        case 3: {
            cout << "输入专业：";
            string str;
            cin >> str;
            students[num].setName(str);
            break;
        }
        case 4: {
            cout << "输入年级：";
            int str;
            cin >> str;
            students[num].setGrade(str);
            break;
        }
        default:
            cout << "输入错误！" << endl;
    }

}

void StudentManager::del() {
    cout << "输入要删除的学号：";
    string id;
    cin >> id;
    int num = student_link.getNumById(id);
    if (num == -1) {
        cout << "未找到" << endl;
        return;
    }
    cout << "原信息：";
    print(students[num]);
    cout << "确认删除（Yes/No）：";
    string str;
    cin >> str;
    if (str == "Yes") {
        student_link.del(students[num].getId());
        score_link.deleteByStudentId(students[num].getId());
        cout << "删除成功" << endl;
    }

}

void StudentManager::findById() {
    cout << "输入学号：";
    string id;
    cin >> id;
    for (auto &s: students) {
        if (s.getId() == id) {
            print(s);
            break;
        }

    }

}

void StudentManager::print(Student s) {
    //cout << "学生信息：" << endl;
    //cout << left << setw(10) << "学号：" << s.getId() << endl;
    //cout << left << setw(10) << "姓名：" << s.getName() << endl;
    //cout << left << setw(10) << "性别：" << s.getSex() << endl;
    //cout << left << setw(10) << "专业：" << s.getProf() << endl;
    //cout << left << setw(10) << "年级：" << s.getGrade() << endl;
    //Line();
    cout << "+------------+------------+------------+--------+" << endl;
    cout << "| " << setw(10) << "学号" << " | " << setw(10) << "姓名" << " | "
         << setw(10) << "专业" << " | " << setw(6) << "年级" << " |" << endl;
    cout << "+------------+------------+------------+--------+" << endl;
    {

        cout << "| " << left << setw(10) << s.getId() << " | " << left << setw(10) << s.getName() << " | " << left
             << setw(10)
             << s.getProf() << " | " << left << setw(6) << s.getGrade() << " |" << endl;
    }

    cout << "+------------+------------+------------+--------+" << endl;
    cout << "共有" << 1 << "条结果" << endl;

}

void StudentManager::findByName() {
    cout << "输入姓名：";
    string name;
    cin >> name;
    vector<Student> stu;
    for (auto &s: students) {
        if (s.getName().find(name) != -1)
            stu.push_back(s);
    }
    print(stu);
}

void StudentManager::print(string id) {
    for (auto &s: students) {
        if (s.getId() == id) {
            print(s);
            return;
        }
    }
    print("未找到");

}

void StudentManager::addFromFile() {
    cout << "输入文件名：";
    string filename;
    cin >> filename;
    student_link.load(filename);

}
