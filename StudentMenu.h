//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTMENU_H
#define COURSEWORK_STUDENTMENU_H

#include <iostream>
#include "Database.h"
#include "Display.h"

using namespace std;

class StudentMenu : public Database {
    string id;
    vector<Score> sc;
public:
    StudentMenu(string id) : id(id) {}

    void menu();//菜单

    void getScore();//分数查询

    //void selectCourse();
    void selectCourse();//选课

    void findCourse();//查找课程

    void searchCourse();//模糊查找
};


#endif //COURSEWORK_STUDENTMENU_H
