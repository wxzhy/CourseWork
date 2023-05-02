//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_COURSELINK_H
#define COURSEWORK_COURSELINK_H


#include "Course.h"
#include "Link.h"

class CourseLink : public Link<Course> {
public:
    CourseLink() { load("course.txt"); }
    void add(string id,string teacherId,string name,string desc);
    void update(string id,string teacherId,string name,string desc);
};


#endif //COURSEWORK_COURSELINK_H
