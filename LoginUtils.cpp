//
// Created by Admin on 2023/5/2.
//

#include "LoginUtils.h"
#include "Database.h"
#include "Display.h"
#include "AdminMenu.h"
#include "TeacherMenu.h"
#include "StudentMenu.h"
#include<conio.h>

void LoginUtils::login() {
    while (true) {
        cout << "选择身份：" << endl;
        cout << "1.管理员" << endl;
        cout << "2.教师" << endl;
        cout << "3.学生" << endl;
        cout << "4.修改密码" << endl;
        cout << "0.退出" << endl;
        cout << "请输入：";
        int op;
        cin >> op;
        switch (op) {
            case 1: {
                string result = adminLogin();
                if (result.length())
                    AdminMenu().menu();
                else
                    cout << "密码错误！" << endl;
            }
                break;
            case 2: {
                string result = teacherLogin();
                if (result.length())
                    TeacherMenu(result).menu();
                else
                    cout << "密码错误！" << endl;
            }
                break;
            case 3: {
                string result = studentLogin();
                if (result.length())
                    StudentMenu(result).menu();
                else
                    cout << "密码错误！" << endl;
            }
                break;
            case 4:
                updatePassword();
                break;
            case 0:
                return;
            default:
                cout << "登录失败！" << endl;
        }
    }
}

string LoginUtils::teacherLogin() {
    string username, password;
    cout << "输入用户名：";
    cin >> username;
    cout << "输入密码：";
    password = PassRead();
    for (auto &s: teachers) {
        if (s.getId() == username && s.checkPassword(password)) {
            TeacherMenu t(username);
            return username;
        }
    }
    return "";

}

string LoginUtils::adminLogin() {
    string username, password;
    cout << "输入用户名：";
    cin >> username;
    cout << "输入密码：";
    password = PassRead();
    ifstream in("admin.txt");
    string uname, upass;
    in >> uname >> upass;
    if (username == uname && password == upass) {
        return username;
    } else
        return "";

}

string LoginUtils::studentLogin() {
    string username, password;
    cout << "输入用户名：";
    cin >> username;
    cout << "输入密码：";
    password = PassRead();
    for (auto &s: students) {
        if (s.getId() == username && s.checkPassword(password)) {
            return username;
        }
    }
    return "";
}


void LoginUtils::updatePassword() {
    cout << "选择身份：" << endl;
    cout << "1.管理员" << endl;
    cout << "2.教师" << endl;
    cout << "3.学生" << endl;
    cout << "请输入：";
    int op;
    cin >> op;
    switch (op) {
        case 1: {
            string result = adminLogin();
            if (result.length()) {
                string username, password;
                cout << "请输入新用户名：";
                cin >> username;
                cout << "请输入新密码：";
                password = PassRead();
                ofstream file("admin.txt");
                file << username << '\t' << password;
                file.close();
                cout << "修改成功！" << endl;
                return;
            } else { cout << "密码错误！" << endl; }
        }
            break;
        case 2: {
            string result = teacherLogin();
            if (result.length()) {

                cout << "请输入新密码：";
                string password = PassRead();
                teacher_link.updatePassword(result, password);
                cout << "修改成功！" << endl;
                return;
            } else { cout << "密码错误！" << endl; }
        }
            break;
        case 3: {
            string result = studentLogin();
            if (result.length()) {
                cout << "请输入新密码：";
                string password = PassRead();
                student_link.updatePassword(result, password);
                cout << "修改成功！" << endl;
                return;
            } else { cout << "密码错误！" << endl; }
        }
            break;
        default:
            cout << "登录失败！" << endl;
    }

}
