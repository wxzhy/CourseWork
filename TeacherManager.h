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

class TeacherManager:public Database,public Display {
public:
    void menu();
    void print(Teacher s);
    void print(string id);

    void displayAll();

    void add();

    void edit();

    void del();

    void findByName();

    void findById();

    void print(vector<Teacher> &s);

    void loadFromFile();
};


#endif //COURSEWORK_TEACHERMANAGER_H
