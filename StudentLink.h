//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_STUDENTLINK_H
#define COURSEWORK_STUDENTLINK_H


#include "Student.h"
#include "Link.h"

class StudentLink: public Link<Student>{

public:
    StudentLink(){load("student.txt");}
};


#endif //COURSEWORK_STUDENTLINK_H
