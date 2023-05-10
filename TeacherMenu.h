//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_TEACHERMENU_H
#define COURSEWORK_TEACHERMENU_H
#include <string>
#include <vector>
#include "Database.h"
#include "Display.h"

using namespace std;
//class TeacherMenu : public Database, public Display {
class TeacherMenu : public Database {//TeacherMenu类的声明
    string id;//工号
    vector<int> courseNums;//存储该教师的课程
    vector<int> studentNums;//存储该课程的学生
    int choiced = 0;  //界面选中的课程 -1:退回上级菜单；0：待选课程；其他：已经选中课程
public:
    TeacherMenu(string id) : id(id) {}//构造函数
    void menu();//菜单
    void getCourses();//获取课程
    void courseMenu(int courseNum);//课程菜单
    void addCourse();//添加课程
    void addScore();//添加成绩
    void showCourse();//显示课程
    void showScore(int courseNum);//显示分数
    void editScore();//修改成绩
    void calculate();//计算平均分
    void sortByScore();//按分数排序
    void sortById();//按学号排序
};


#endif //COURSEWORK_TEACHERMENU_H
