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
        cout << "ѡ����ݣ�" << endl;
        cout << "1.����Ա" << endl;
        cout << "2.��ʦ" << endl;
        cout << "3.ѧ��" << endl;
        cout << "4.�޸�����" << endl;
        cout << "0.�˳�" << endl;
        cout << "�����룺";
        int op;
        cin >> op;
        switch (op) {
            case 1: {
                string result = adminLogin();
                if (result.length())
                    AdminMenu().menu();
                else
                    cout << "�������" << endl;
            }
                break;
            case 2: {
                string result = teacherLogin();
                if (result.length())
                    TeacherMenu(result).menu();
                else
                    cout << "�������" << endl;
            }
                break;
            case 3: {
                string result = studentLogin();
                if (result.length())
                    StudentMenu(result).menu();
                else
                    cout << "�������" << endl;
            }
                break;
            case 4:
                updatePassword();
                break;
            case 0:
                return;
            default:
                cout << "��¼ʧ�ܣ�" << endl;
        }
    }
}

string LoginUtils::teacherLogin() {
    string username, password;
    cout << "�����û�����";
    cin >> username;
    cout << "�������룺";
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
    ifstream in("admin.txt");
    string uname, pass;
    if (in.fail()) {
        in.close();
        cout << "��admin.txtʧ�ܣ�" << endl;
        cout << "�Ƿ񴴽�(Yes/No):";
        string str;
        cin >> str;
        if (str == "Yes") {
            ofstream out("admin.txt");
            cout << "�����û�����";
            cin >> uname;
            cout << "�������룺";
            pass = PassRead();
            out << uname << '\t' << pass;
            out.close();
            cout << "�����ɹ�" << endl;
            return uname;
        } else
            exit(1);
    } else {
        in >> uname >> pass;
    }
    in >> uname >> pass;
    string username, password;
    cout << "�����û�����";
    cin >> username;
    cout << "�������룺";
    password = PassRead();
    if (username == uname && password == pass) {
        return username;
    } else
        return "";

}

string LoginUtils::studentLogin() {
    string username, password;
    cout << "�����û�����";
    cin >> username;
    cout << "�������룺";
    password = PassRead();
    for (auto &s: students) {
        if (s.getId() == username && s.checkPassword(password)) {
            return username;
        }
    }
    return "";
}


void LoginUtils::updatePassword() {
    cout << "ѡ����ݣ�" << endl;
    cout << "1.����Ա" << endl;
    cout << "2.��ʦ" << endl;
    cout << "3.ѧ��" << endl;
    cout << "�����룺";
    int op;
    cin >> op;
    switch (op) {
        case 1: {
            string result = adminLogin();
            if (result.length()) {
                string username, password;
                cout << "���������û�����";
                cin >> username;
                cout << "�����������룺";
                password = PassRead();
                ofstream file("admin.txt");
                file << username << '\t' << password;
                file.close();
                cout << "�޸ĳɹ���" << endl;
                return;
            } else { cout << "�������" << endl; }
        }
            break;
        case 2: {
            string result = teacherLogin();
            if (result.length()) {

                cout << "�����������룺";
                string password = PassRead();
                teacher_link.updatePassword(result, password);
                cout << "�޸ĳɹ���" << endl;
                return;
            } else { cout << "�������" << endl; }
        }
            break;
        case 3: {
            string result = studentLogin();
            if (result.length()) {
                cout << "�����������룺";
                string password = PassRead();
                student_link.updatePassword(result, password);
                cout << "�޸ĳɹ���" << endl;
                return;
            } else { cout << "�������" << endl; }
        }
            break;
        default:
            cout << "��¼ʧ�ܣ�" << endl;
    }

}
