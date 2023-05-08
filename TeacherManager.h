//
// Created by Admin on 2023/5/3.
//

#ifndef COURSEWORK_TEACHERMANAGER_H
#define COURSEWORK_TEACHERMANAGER_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Teacher.h"
#include "Student.h"
#include "Display.h"
#include "Database.h"

using namespace std;

//class TeacherManager:public Database,public Display {
class TeacherManager : public Database {
public:
    void menu();//菜单

    void print(Teacher s);

    void print(string id);//打印信息

    void displayAll();//显示所有

    void add();//添加

    void edit();//修改

    void del();//删除

    void findByName();//按姓名查询

    void findById();//按工号查询

    void print(vector<Teacher> &s);

    void loadFromFile();
};


#endif //COURSEWORK_TEACHERMANAGER_H
