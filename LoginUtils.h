//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_LOGINUTILS_H
#define COURSEWORK_LOGINUTILS_H
#include<string>
#include<iostream>
#include "Database.h"
#include "Display.h"

using namespace std;

//class LoginUtils : public Database, public Display {
class LoginUtils : public Database {
public:
    void login();//登录界面

    string adminLogin();//管理员登录

    string teacherLogin();//

    string studentLogin();

    void updatePassword();
};


#endif //COURSEWORK_LOGINUTILS_H
