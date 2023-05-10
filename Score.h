//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_SCORE_H
#define COURSEWORK_SCORE_H

#include <string>

using namespace std;

class Score {//Score类的声明
    string studentId, courseId;//学生id,课程id
    float value;//分数
public:
    Score() {}//构造函数
    Score(string studentId, string courseId, float value) : studentId(studentId), courseId(courseId), value(value) {}

    string getId() { return studentId; }

    string getStudentId() { return studentId; }//获得学生id
    void setStudentId(string &s) { studentId = s; }//设置学生id
    string getCourseId() { return courseId; }//获得课程id
    void setCourseId(string &s) { courseId = s; }//设置课程id
    float getValue() { return value; }//获得分数
    void setValue(float value) { this->value = value; }//设置分数
    friend ofstream &operator<<(ofstream &out, Score &c);//重载<<
    friend ifstream &operator>>(ifstream &in, Score &c);//重载>>
};


#endif //COURSEWORK_SCORE_H
