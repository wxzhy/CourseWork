//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_COURSE_H
#define COURSEWORK_COURSE_H

#include <string>

using namespace std;

class Course {
    string id, teacherId, name, desc;//教师id,名称，简介
public:
    string getId() { return id; }//获得编号
    void setId(string &id) { this->id = id; }//设置编号
    string getTid() { return teacherId; }//获得教师编号
    void setTid(string &tid) { this->teacherId = tid; }//设置教师编号
    string getName() { return name; }//获得姓名
    void setName(string &name) { this->name = name; }//设置姓名
    string getDesc() { return desc; }//获得简介
    void setDesc(string &desc) { this->desc = desc; }//设置简介
    friend ofstream &operator<<(ofstream &out, Course &c);//重载“〈〈”
    friend ifstream &operator>>(ifstream &in, Course &c);//重载“〈〈”

};


#endif //COURSEWORK_COURSE_H
