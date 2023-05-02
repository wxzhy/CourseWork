//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_TEACHERLINK_H
#define COURSEWORK_TEACHERLINK_H


#include "Teacher.h"
#include "Link.h"

class TeacherLink: public Link<Teacher>  {
public:
    TeacherLink(){load("teacher.txt");}
    void modify();

};


#endif //COURSEWORK_TEACHERLINK_H
