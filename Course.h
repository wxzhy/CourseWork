//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_COURSE_H
#define COURSEWORK_COURSE_H

#include <string>

using namespace std;

class Course {//Course类的声明
    string id, teacherId, name;//教师id,名称，简介
    int current, max;//当前人数，最大人数
public:
    Course() { current = 0; }//构造函数
    Course(string id, string teacherId, string name, int max) : id(id), teacherId(teacherId), name(name), max(max),
                                                                current(0) {}

    string getId() { return id; }//获得编号
    void setId(string &id) { this->id = id; }//设置编号
    string getTeacherId() { return teacherId; }//获得教师编号
    void setTeacherId(string &tid) { this->teacherId = tid; }//设置教师编号
    string getName() { return name; }//获得名称
    void setName(string &name) { this->name = name; }//设置名称
    int getCurrent() { return current; }//获得人数
    void addCurrent() { current++; }//增加人数
    int getMax() { return max; }//获得最大人数
    void setMax(int max) { this->max = max; }//设置最大认识
    friend ofstream &operator<<(ofstream &out, Course &c);//重载“〈〈”
    friend ifstream &operator>>(ifstream &in, Course &c);//重载“〈〈”
};


#endif //COURSEWORK_COURSE_H
