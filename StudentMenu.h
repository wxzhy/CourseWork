//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTMENU_H
#define COURSEWORK_STUDENTMENU_H

#include <iostream>
#include "Database.h"
#include "Display.h"

using namespace std;

class StudentMenu : public Database {//StudentMenu�������
    string id;//ѧ��
    vector<Score> sc;//�����б�
public:
    StudentMenu(string id) : id(id) {}//���캯��
    void menu();//�˵�
    void getScore();//������ѯ
    //void selectCourse();
    void selectCourse();//ѡ��
    void findCourse();//���ҿγ�
    void searchCourse();//ģ������
};


#endif //COURSEWORK_STUDENTMENU_H
