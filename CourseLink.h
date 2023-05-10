//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_COURSELINK_H
#define COURSEWORK_COURSELINK_H


#include "Course.h"
#include "Link.h"

class CourseLink : public Link<Course> {//CourseLink类的声明
public:
    CourseLink() = default;

    void update(string id, string teacherId, string name, string desc);//修改
    void add(string id, string teacherId, string name, int num);//添加
    vector<int> getNumByTeacherId(string id);//按教师工号查询
    string getTeacherId(string id);//获得教师id
    void addCurrent(string id);//选课
    void sortById();//按编号排序
};


#endif //COURSEWORK_COURSELINK_H
