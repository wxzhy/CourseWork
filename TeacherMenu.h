//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_TEACHERMENU_H
#define COURSEWORK_TEACHERMENU_H
#include <string>
using namespace std;
class TeacherMenu {
    string id;
public:
    TeacherMenu(string id):id(id){}
    void teacherMenu();
    void addCourse();

    void addScore();

    void showCourse();

    void showScore();

    void changePassword();

};


#endif //COURSEWORK_TEACHERMENU_H
