//
// Created by Admin on 2023/5/3.
//

#ifndef COURSEWORK_SCOREMANAGER_H
#define COURSEWORK_SCOREMANAGER_H


#include "Display.h"
#include "Database.h"
#include <iostream>

using namespace std;

//class ScoreManager : public Database, public Display {
class ScoreManager : public Database {//ScoreManager类的声明
public:
    void menu();//菜单
    void addScore();//添加
    void editScore();//修改
    void delScore();//删除
    void showAll();//展示所有
    void print(vector<Score> s);//显示多个分数
    void del();//删除
    void queryByCourse();//按课程查询
    void addFromFile();//从文件加载
};


#endif //COURSEWORK_SCOREMANAGER_H
