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
class TeacherMenu : public Database, public Display {
    string id;
    vector<int> courseNums;//存储该教师的课程
    vector<int> studentNums;//存储该课程的学生
public:
    TeacherMenu(string id) : id(id) {}

    void menu();

    void getCourses();

    void courseMenu(int courseNum);//课程菜单
    void addCourse();

    void addScore();

    void showCourse();

    void showScore();

    void changePassword();

    void AddScore();

    void editScore();

    void calculate();

    void sortByScore();

    void sortById();
};


#endif //COURSEWORK_TEACHERMENU_H
