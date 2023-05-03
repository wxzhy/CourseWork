//
// Created by Admin on 2023/5/2.
//

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "Display.h"
using namespace std;
void Display::start() {
    system("cls");
    system("chcp 936>nul");
    system("color 2e");
    cout<<"=================================="<<endl;
    cout << "        教室管理系统V1.0             " << endl << endl;
    cout << "       Created By GaoTian        " << endl;
    cout<<"=================================="<<endl;

}
void Display::Head() {
    cout<<right<<setw(5)<<"学生信息管理系统"<<endl;

}

void Display::Line() {
    cout<<"--------------------------------"<<endl;
}

void Display::boldLine() {
    cout<<"================================"<<endl;

}

void Display::Head(string s) {
    cout<<right<<setw(20)<<"学生信息管理系统"<<endl;
    cout<<right<<setw(20)<<s<<endl;

}

