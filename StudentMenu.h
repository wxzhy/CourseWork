//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTMENU_H
#define COURSEWORK_STUDENTMENU_H
#include <iostream>
using namespace std;

class StudentMenu {
    int id;
public:
    StudentMenu(int id) : id(id) {}
    void menu();
    void getScore();

    //void selectCourse();
};


#endif //COURSEWORK_STUDENTMENU_H
