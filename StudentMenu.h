//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTMENU_H
#define COURSEWORK_STUDENTMENU_H

#include <iostream>
#include "Database.h"
#include "Display.h"

using namespace std;

class StudentMenu : public Database {
    string id;
    vector<Score> sc;
public:
    StudentMenu(string id) : id(id) {}

    void menu();//�˵�

    void getScore();//������ѯ

    //void selectCourse();
    void selectCourse();//ѡ��

    void findCourse();//���ҿγ�

    void searchCourse();//ģ������
};


#endif //COURSEWORK_STUDENTMENU_H
