//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_STUDENT_H
#define COURSEWORK_STUDENT_H


#include <vector>
#include "User.h"
/*typedef struct Score{
    string courseId;
    string courseName;
    float value;
}score;*/

class Student : public User {//Student类的声明
    string prof;//专业
    int grade;//专业，年级
public:
    Student() = default;//构造函数
    Student(string id, string name, string sex, string prof, int grade) : User(id, name, sex), prof(prof),
                                                                          grade(grade) {}

    string getProf() { return prof; }   //获得专业
    void setProf(string &prof) { this->prof = prof; }//设置专业
    int getGrade() { return grade; }//获得年级
    void setGrade(int grade) { this->grade = grade; }//设置年级
    friend ofstream &operator<<(ofstream &out, Student &c);//重载“〈〈”
    friend ifstream &operator>>(ifstream &in, Student &c);//重载“〈〈”
};


#endif //COURSEWORK_STUDENT_H
