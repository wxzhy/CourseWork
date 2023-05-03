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
class TeacherMenu:public Database,public Display {
    string id;
    vector<int> courseNums;
    vector<int> studentNums;
public:
    TeacherMenu(string id):id(id){}
    void menu();
    void getCourses();
    void courseMenu(int courseNum);
    void addCourse();

    void addScore();

    void showCourse();

    void showScore();

    void changePassword();

    void AddScore();
};


#endif //COURSEWORK_TEACHERMENU_H
