//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_COURSELINK_H
#define COURSEWORK_COURSELINK_H


#include "Course.h"
#include "Link.h"

class CourseLink : public Link<Course> {
public:
    CourseLink() {}

    void update(string id, string teacherId, string name, string desc);

    void add(string id, string teacherId, string name, int num);

    vector<int> getNumByTeacherId(string id);

    string getTeacherId(string id);

    void addCurrent(string id);
};


#endif //COURSEWORK_COURSELINK_H
