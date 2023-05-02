//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_SCORE_H
#define COURSEWORK_SCORE_H

#include <string>

using namespace std;

class Score {
    string studentId, courseId;//学生id,课程id
    int value;//分数
public:
    string getSid() { return studentId; }//获得学生id
    void setSid(string &s) { studentId = s; }//设置学生id
    string getCid() { return courseId; }//获得课程id
    void setCid(string &s) { courseId = s; }//设置课程id
    int getValue() { return value; }//获得分数
    void setValue(int value) { this->value = value; }//设置分数
    friend ofstream &operator<<(ofstream &out, Score &c);

    friend ifstream &operator>>(ifstream &in, Score &c);
};


#endif //COURSEWORK_SCORE_H
