//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_LOGINUTILS_H
#define COURSEWORK_LOGINUTILS_H
#include<string>
#include<iostream>
#include "Database.h"
#include "Display.h"

using namespace std;

//class LoginUtils : public Database, public Display {
class LoginUtils : public Database {//LoginUtils�������
public:
    void login();//��¼����
    string adminLogin();//����Ա��¼
    string teacherLogin();//��ʦ��¼
    string studentLogin();//ѧ����¼
    void updatePassword();//�޸�����
};


#endif //COURSEWORK_LOGINUTILS_H
