//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_TEACHERLINK_H
#define COURSEWORK_TEACHERLINK_H


#include "Teacher.h"
#include "Link.h"

class TeacherLink : public Link<Teacher> {//TeacherLink类的声明
public:
    TeacherLink() = default;

    void add(string id, string name, string sex, string depart, string phone);//添加
    void updatePassword(string id, string password);//修改密码
};


#endif //COURSEWORK_TEACHERLINK_H
