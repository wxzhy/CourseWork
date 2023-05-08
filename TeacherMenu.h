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
class TeacherMenu : public Database {
    string id;
    vector<int> courseNums;//存储该教师的课程
    vector<int> studentNums;//存储该课程的学生
    int choiced = 0;  //界面选中的课程 -1:退回上级菜单；0：待选课程；其他：已经选中课程
public:
    TeacherMenu(string id) : id(id) {}

    void menu();

    void getCourses();

    void courseMenu(int courseNum);//课程菜单

    void addCourse();

    void addScore();

    void showCourse();

    void showScore(int courseNum);

    void changePassword();

    void AddScore();

    void editScore();

    void calculate();

    void sortByScore();

    void sortById();
};


#endif //COURSEWORK_TEACHERMENU_H
