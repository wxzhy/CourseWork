//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTMENU_H
#define COURSEWORK_STUDENTMENU_H

#include <iostream>
#include "Database.h"

using namespace std;

class StudentMenu : public Database {
    string id;
    vector<Score> sc;
public:
    StudentMenu(string id) : id(id) {}

    void menu();

    void getScore();

    //void selectCourse();
    void selectCourse();

    void findCourse();

    void searchCourse();
};


#endif //COURSEWORK_STUDENTMENU_H
