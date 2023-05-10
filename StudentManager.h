//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTMANAGER_H
#define COURSEWORK_STUDENTMANAGER_H

#include "Database.h"
#include "Display.h"
#include <iomanip>

//class StudentManager:public Database,public Display {
class StudentManager : public Database {//StudentManager类的声明
public:
    void menu();//菜单
    void print(Student s);//打印学生信息
    void print(string id);//打印学号对应学生信息
    void print(vector<Student> &s);//打印多个学生信息
    void displayAll();//显示所有
    void add();//添加
    void edit();//修改
    void del();//删除
    void findByName();//按姓名查找
    void findById();//按id查找
    void addFromFile();//从文件加载
};


#endif //COURSEWORK_STUDENTMANAGER_H
