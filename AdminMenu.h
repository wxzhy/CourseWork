//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_ADMINMENU_H
#define COURSEWORK_ADMINMENU_H
#include <iostream>
#include <iomanip>
#include "Database.h"
#include "Display.h"

using namespace std;

//class AdminMenu : public Database, public Display {
class AdminMenu : public Database {//AdminMenu类的声明
public:
    void menu();//管理员菜单
};


#endif //COURSEWORK_ADMINMENU_H
