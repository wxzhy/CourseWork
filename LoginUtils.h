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
class LoginUtils : public Database {//LoginUtils类的声明
public:
    void login();//登录界面
    string adminLogin();//管理员登录
    string teacherLogin();//教师登录
    string studentLogin();//学生登录
    void updatePassword();//修改密码
};


#endif //COURSEWORK_LOGINUTILS_H
