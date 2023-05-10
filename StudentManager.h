//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTMANAGER_H
#define COURSEWORK_STUDENTMANAGER_H

#include "Database.h"
#include "Display.h"
#include <iomanip>

//class StudentManager:public Database,public Display {
class StudentManager : public Database {//StudentManager�������
public:
    void menu();//�˵�
    void print(Student s);//��ӡѧ����Ϣ
    void print(string id);//��ӡѧ�Ŷ�Ӧѧ����Ϣ
    void print(vector<Student> &s);//��ӡ���ѧ����Ϣ
    void displayAll();//��ʾ����
    void add();//���
    void edit();//�޸�
    void del();//ɾ��
    void findByName();//����������
    void findById();//��id����
    void addFromFile();//���ļ�����
};


#endif //COURSEWORK_STUDENTMANAGER_H
