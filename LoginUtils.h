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

class LoginUtils : public Database, public Display {
public:
    void login();

    unsigned selectLoginType();

    void adminLogin(string username, string password);

    void teacherLogin(string username, string password);

    void studentLogin(string username, string password);
};


#endif //COURSEWORK_LOGINUTILS_H