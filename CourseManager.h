//
// Created by Admin on 2023/5/3.
//

#ifndef COURSEWORK_COURSEMANAGER_H
#define COURSEWORK_COURSEMANAGER_H

#include<iostream>
#include <vector>
#include "Course.h"
#include "Database.h"
#include "Display.h"
#include <iomanip>

using namespace std;

class CourseManager : public Database {
    //class CourseManager : public Database, public Display {
public:
    void menu();

    void addCourse();//添加

    void search();//搜索

    void showCourse();//展示课程

    void print(Course c);//显示

    void print(vector<Course> c);

    void deleteCourse();//删除

    void editCourse();//修改

    void findById();//按编号查询

    void addFromFile();//从文件添加
};


#endif //COURSEWORK_COURSEMANAGER_H
