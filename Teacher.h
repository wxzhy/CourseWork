//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_TEACHER_H
#define COURSEWORK_TEACHER_H


#include "User.h"

class Teacher : public User {//Teacher�������
    string depart, phone;//���ţ��ֻ�
public:
    Teacher() = default;//���캯��
    Teacher(string id, string name, string sex, string depart, string phone) : User(id, name, sex), depart(depart),
                                                                               phone(phone) {};

    string getDepart() { return depart; };//��ò���
    void setDepart(string depart) { this->depart = depart; }//���ò���
    string getPhone() { return phone; }//��õ绰
    void setPhone(string phone) { this->phone = phone; }//���õ绰
    friend ofstream &operator<<(ofstream &out, Teacher &c);
    friend ifstream &operator>>(ifstream &in, Teacher &c);
};


#endif //COURSEWORK_TEACHER_H
