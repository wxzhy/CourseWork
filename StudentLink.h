//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTLINK_H
#define COURSEWORK_STUDENTLINK_H


#include "Student.h"
#include "Link.h"

class StudentLink : public Link<Student> {//StudentLink�������
public:
    StudentLink() {}

    void add(string id, string name, string sex, string prof, int grade) {//���
        Student s(id, name, sex, prof, grade);
        link.push_back(s);
    }

    void update(string id, string name, string sex, string prof, int grade);//�޸�
    void updatePassword(string id, string password);//��������
};


#endif //COURSEWORK_STUDENTLINK_H
