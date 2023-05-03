//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTMANAGER_H
#define COURSEWORK_STUDENTMANAGER_H

#include "Database.h"
#include "Display.h"
#include <iomanip>

class StudentManager:public Database,public Display {
public:
    void menu();
    void print(Student s);
    void print(string id);

    void print(vector<Student> &s);

    void displayAll();
    void add();
    void edit();

    void del();
    void findByName();

    void findById();
};


#endif //COURSEWORK_STUDENTMANAGER_H
