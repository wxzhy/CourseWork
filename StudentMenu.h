//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTMENU_H
#define COURSEWORK_STUDENTMENU_H

#include <iostream>
#include "Database.h"
#include "Display.h"

using namespace std;

class StudentMenu : public Database {//StudentMenu类的声明
    string id;//学号
    vector<Score> sc;//分数列表
public:
    StudentMenu(string id) : id(id) {}//构造函数
    void menu();//菜单
    void getScore();//分数查询
    //void selectCourse();
    void selectCourse();//选课
    void findCourse();//查找课程
    void searchCourse();//模糊查找
};


#endif //COURSEWORK_STUDENTMENU_H
