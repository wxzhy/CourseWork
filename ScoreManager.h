//
// Created by Admin on 2023/5/3.
//

#ifndef COURSEWORK_SCOREMANAGER_H
#define COURSEWORK_SCOREMANAGER_H


#include "Display.h"
#include "Database.h"
#include <iostream>

using namespace std;

//class ScoreManager : public Database, public Display {
class ScoreManager : public Database {//ScoreManager�������
public:
    void menu();//�˵�
    void addScore();//���
    void editScore();//�޸�
    void delScore();//ɾ��
    void showAll();//չʾ����
    void print(vector<Score> s);//��ʾ�������
    void del();//ɾ��
    void queryByCourse();//���γ̲�ѯ
    void addFromFile();//���ļ�����
};


#endif //COURSEWORK_SCOREMANAGER_H
