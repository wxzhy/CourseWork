//
// Created by Admin on 2023/5/3.
//

#include "TeacherManager.h"

void TeacherManager::menu() {
    while (true) {
        Display::Head(">>管理模块>>教师管理");
        cout << "     1.查看全部教师" << endl;
        cout << "     2.添加教师" << endl;
        cout << "     3.修改教师" << endl;
        cout << "     4.删除教师" << endl;
        cout << "     5.按工号查询" << endl;
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
                loadFromFile();
                break;
            case 0:
                return;
            default:
                cout << "输入错误！" << endl;

        }
    }
}

void TeacherManager::displayAll() {
    print(teachers);

}

void TeacherManager::print(vector<Teacher> &s) {
    if (s.empty()) {
        cout << "未找到" << endl;
        return;
    }
    int n = 0;
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    cout << "|     工号     |     姓名     |     部门     |          电话          |" << endl;
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    for (auto &i: s) {
        cout << "| " << setw(12) << i.getId() << " | " << setw(12) << i.getName() << " | " << setw(12) << i.getDepart()
             << " | " << setw(22) << i.getPhone() << " |" << endl;
        n++;
        if (n % 20 == 0)
            system("pause>nul");
    }
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    cout << "共有" << n << "条结果" << endl;
    system("pause>nul");
}


void TeacherManager::add() {
    Teacher teacher;
    string str;
    cout << "输入工号：";
    cin >> str;
    if (teacher_link.ifExist(str)) {
        cout << "该工号已存在" << endl;
        return;
    }
    teacher.setId(str);
    teacher.setPassword(str);
    cout << "输入姓名：";
    cin >> str;
    teacher.setName(str);
    cout << "输入性别：";
    cin >> str;
    teacher.setSex(str);
    cout << "输入部门：";
    cin >> str;
    teacher.setDepart(str);
    cout << "输入电话：";
    cin >> str;
    teacher.setPhone(str);
    teachers.push_back(teacher);
    teacher_link.sortById();

}

void TeacherManager::edit() {
    //findByName();
    cout << "输入要修改的工号：";
    string id;
    cin >> id;
    int num = teacher_link.getNumById(id);
    if (num == -1) {
        Display::Result();
        cout << "未找到" << endl;
        return;
    }
    //cout << "原信息：";
    Display::Message("原信息");
    print(teachers[num]);
    Display::Head(">>管理模块>>教师管理>>修改教师");
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
            teachers[num].setName(str);
            break;
        }
        case 2: {
            cout << "输入性别：";
            string str;
            cin >> str;
            teachers[num].setSex(str);
            break;
        }
        case 3: {
            cout << "输入部门：";
            string str;
            cin >> str;
            teachers[num].setName(str);
            break;
        }
        case 4: {
            cout << "输入电话：";
            string str;
            cin >> str;
            teachers[num].setPhone(str);
            break;
        }
        default:
            cout << "输入错误！" << endl;
    }

}

void TeacherManager::del() {
    cout << "输入要删除的工号：";
    string id;
    cin >> id;
    int num = teacher_link.getNumById(id);
    if (num == -1) {
        cout << "未找到" << endl;
        return;
    }
    cout << "原信息：";
    print(teachers[num]);
    cout << "确认删除（Yes/No）：";
    string str;
    cin >> str;
    if (str == "Yes") {
        teacher_link.del(teachers[num].getId());
        cout << "删除成功" << endl;
    }
}

void TeacherManager::findById() {
    cout << "输入工号：";
    string id;
    cin >> id;
    for (auto &s: teachers) {
        if (s.getId() == id) {
            Display::Message();
            print(s);
            break;
        }

    }

}

void TeacherManager::print(Teacher s) {
    //cout << "教师信息：" << endl;
    //cout << left << setw(10) << "工号：" << s.getId() << endl;
    //cout << left << setw(10) << "姓名：" << s.getName() << endl;
    //cout << left << setw(10) << "性别：" << s.getSex() << endl;
    //cout << left << setw(10) << "专业：" << s.getDepart() << endl;
    //cout << left << setw(10) << "年级：" << s.getPhone() << endl;
    //Line();
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    cout << "|     工号     |     姓名     |     部门     |          电话          |" << endl;
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    {
        cout << "| " << setw(12) << s.getId() << " | " << setw(12) << s.getName() << " | " << setw(12) << s.getDepart()
             << " | " << setw(22) << s.getPhone() << " |" << endl;
    }
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    cout << "共有" << 1 << "条结果" << endl;
    system("pause>nul");

}

void TeacherManager::findByName() {
    cout << "输入姓名：";
    string name;
    cin >> name;
    vector<Teacher> stu;
    for (auto &s: teachers) {
        if (s.getName().find(name) != -1)
            stu.push_back(s);
    }
    Display::Message();
    print(stu);
}

void TeacherManager::print(string id) {
    for (auto &s: teachers) {
        if (s.getId() == id) {
            print(s);
            return;
        }
    }
    Display::Result();
    print("未找到");

}

void TeacherManager::loadFromFile() {
    cout << "输入文件名：";
    string filename;
    cin >> filename;
    teacher_link.load(filename);

}
