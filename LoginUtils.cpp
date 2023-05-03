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
    cout << "�����û�����";
    cin >> username;
    cout << "�������룺";
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
            cout << "��¼ʧ�ܣ�" << endl;
    }
}

void LoginUtils::teacherLogin(string username, string password) {

    for (auto &s: teachers) {
        if (s.getId() == username && s.checkPassword(password)) {
            //TeacherMenu(username);
            return;
        }
    }
    cout << "�������" << endl;

}

void LoginUtils::adminLogin(string username, string password) {
    ifstream in("admin.txt");
    string uname, upass;
    in >> uname >> upass;
    if (username == uname && password == upass) {
        AdminMenu a;
        a.menu();
    } else
        cout << "�������" << endl;
    in.close();
}

void LoginUtils::studentLogin(string username, string password) {
    for (auto &s: students) {
        if (s.getId() == username && s.checkPassword(password)) {
            //StudentMenu(username);
            return;
        }
    }
    cout << "�������" << endl;
}

unsigned LoginUtils::selectLoginType() {
    cout << "ѡ����ݣ�" << endl;
    cout << "1.����Ա" << endl;
    cout << "2.��ʦ" << endl;
    cout << "3.ѧ��" << endl;
    cout << "�����룺";
    int op;
    cin >> op;
    return op;
}
