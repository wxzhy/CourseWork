//
// Created by Admin on 2023/5/2.
//

#include "LoginUtils.h"
#include "Database.h"
#include "Display.h"
#include "AdminMenu.h"
#include<conio.h>

void LoginUtils::login() {
    unsigned type = selectLoginType();
    string username, password;
    cout << "输入用户名：";
    cin >> username;
    cout << "输入密码：";
    password = PassRead();
    switch (type) {
        case 1:
            adminLogin(username, password);
            break;
        case 2:
            teacherLogin(username, password);
            break;
        case 3:
            studentLogin(username, password);
            break;
        default:
            cout << "登录失败！" << endl;
    }
}

void LoginUtils::teacherLogin(string username, string password) {

    for (auto &s: teachers) {
        if (s.getId() == username && s.checkPassword(password)) {
            //TeacherMenu(username);
            return;
        }
    }
    cout << "密码错误！" << endl;

}

void LoginUtils::adminLogin(string username, string password) {
    ifstream in("admin.txt");
    string uname, upass;
    in >> uname >> upass;
    if (username == uname && password == upass) {
        AdminMenu a;
        a.menu();
    } else
        cout << "密码错误！" << endl;
    in.close();
}

void LoginUtils::studentLogin(string username, string password) {
    for (auto &s: students) {
        if (s.getId() == username && s.checkPassword(password)) {
            //StudentMenu(username);
            return;
        }
    }
    cout << "密码错误！" << endl;
}

unsigned LoginUtils::selectLoginType() {
    cout << "选择身份：" << endl;
    cout << "1.管理员" << endl;
    cout << "2.教师" << endl;
    cout << "3.学生" << endl;
    cout << "请输入：";
    int op;
    cin >> op;
    return op;
}
