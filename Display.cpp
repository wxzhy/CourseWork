//
// Created by Admin on 2023/5/2.
//
#include "Display.h"
#include "Database.h"
#include "LoginUtils.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>


using namespace std;

void Display::start() {
    system("cls");
    system("chcp 936>nul");
    system("color 2e");
    cout << "==================================" << endl;
    cout << "        ���ҹ���ϵͳV1.0             " << endl << endl;
    cout << "              " << endl;
    cout << "==================================" << endl;

}

void Display::Head() {
    cout << "                                                " << endl;
    cout << right << setw(5) << "ѧ����Ϣ����ϵͳ" << endl;

}

void Display::Line() {
    cout << "-------------------------------------------------" << endl;
}

void Display::boldLine() {
    cout << "==================================================" << endl;

}

void Display::Tail() {
    cout << "                                                " << endl;
    boldLine();

}

void Display::Result() {
    Result("");
}

void Display::Result(string s) {
    cout << "-----------ִ�н��---------------" << endl;
    if (!s.compare("")) {
        cout << s << endl;
        cout << "                                                " << endl;
    }
}

void Display::Message() {
    cout << "-----------��Ϣ��ʾ---------------" << endl;
}

void Display::Message(string s) {
    cout << "-----------" << s << "---------------" << endl;

}

void Display::Head(string s) {
    Head(s, "");
}

void Display::Head(string s1, string s2) {
    system("timeout /t 1 >nul&&cls&&cls&&color 0e");
    cout << "                                                " << endl;
    boldLine();
    cout << s1 << endl;
    boldLine();
    cout << "                                                " << endl;
    cout << "   ��ѡ��" << s2 << "��                       " << endl;
    cout << "                                                " << endl;
    //cout << right << setw(20) << "ѧ����Ϣ����ϵͳ" << endl;
    //cout << right << setw(20) << s << endl;

}

string Display::PassRead() {
    char c;
    string s;
    c = getch();
    while (c != '\r') {
        if (c == '\b') {
            if (s.length()) {
                cout << "\b \b";
                s.pop_back();
            }
        } else {
            s.push_back(c);
            cout << "*";
        }
        c = getch();
    }
    cout << '\n';

    return s;
}