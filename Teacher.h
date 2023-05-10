//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_TEACHER_H
#define COURSEWORK_TEACHER_H


#include "User.h"

class Teacher : public User {//Teacher类的声明
    string depart, phone;//部门，手机
public:
    Teacher() = default;//构造函数
    Teacher(string id, string name, string sex, string depart, string phone) : User(id, name, sex), depart(depart),
                                                                               phone(phone) {};

    string getDepart() { return depart; };//获得部门
    void setDepart(string depart) { this->depart = depart; }//设置部门
    string getPhone() { return phone; }//获得电话
    void setPhone(string phone) { this->phone = phone; }//设置电话
    friend ofstream &operator<<(ofstream &out, Teacher &c);
    friend ifstream &operator>>(ifstream &in, Teacher &c);
};


#endif //COURSEWORK_TEACHER_H
