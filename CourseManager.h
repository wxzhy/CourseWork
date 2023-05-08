//
// Created by Admin on 2023/5/3.
//

#ifndef COURSEWORK_COURSEMANAGER_H
#define COURSEWORK_COURSEMANAGER_H

#include<iostream>
#include <vector>
#include "Course.h"
#include "Database.h"
#include "Display.h"
#include <iomanip>

using namespace std;

class CourseManager : public Database {
    //class CourseManager : public Database, public Display {
public:
    void menu();

    void addCourse();//���

    void search();//����

    void showCourse();//չʾ�γ�

    void print(Course c);//��ʾ

    void print(vector<Course> c);

    void deleteCourse();//ɾ��

    void editCourse();//�޸�

    void findById();//����Ų�ѯ

    void addFromFile();//���ļ����
};


#endif //COURSEWORK_COURSEMANAGER_H
