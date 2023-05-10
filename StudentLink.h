//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTLINK_H
#define COURSEWORK_STUDENTLINK_H


#include "Student.h"
#include "Link.h"

class StudentLink : public Link<Student> {//StudentLink类的声明
public:
    StudentLink() {}

    void add(string id, string name, string sex, string prof, int grade) {//添加
        Student s(id, name, sex, prof, grade);
        link.push_back(s);
    }

    void update(string id, string name, string sex, string prof, int grade);//修改
    void updatePassword(string id, string password);//更新密码
};


#endif //COURSEWORK_STUDENTLINK_H
