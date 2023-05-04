//
// Created by Admin on 2023/5/3.
//

#ifndef COURSEWORK_COURSEMANAGER_H
#define COURSEWORK_COURSEMANAGER_H

#include<iostream>
#include <vector>
#include "Course.h"
#include "Database.h"

using namespace std;


class CourseManager : public Database {
public:
    void menu();

    void addCourse();

    void search();

    void showCourse();

    void print(Course c);

    void print(vector<Course> c);

    void deleteCourse();

    void editCourse();

    void findById();

    void addFromFile();
};


#endif //COURSEWORK_COURSEMANAGER_H
