//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_TEACHERLINK_H
#define COURSEWORK_TEACHERLINK_H


#include "Teacher.h"
#include "Link.h"

class TeacherLink: public Link<Teacher>  {
public:
    TeacherLink(){}
    void add(string id, string name, string sex, string depart, string phone){
        Teacher t(id,name,sex,depart,phone);
        link.push_back(t);
    }
    void modify();

};


#endif //COURSEWORK_TEACHERLINK_H
