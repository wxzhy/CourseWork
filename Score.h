//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_SCORE_H
#define COURSEWORK_SCORE_H

#include <string>

using namespace std;

class Score {
    string studentId, courseId;//ѧ��id,�γ�id
    int value;//����
public:
    string getSid() { return studentId; }//���ѧ��id
    void setSid(string &s) { studentId = s; }//����ѧ��id
    string getCid() { return courseId; }//��ÿγ�id
    void setCid(string &s) { courseId = s; }//���ÿγ�id
    int getValue() { return value; }//��÷���
    void setValue(int value) { this->value = value; }//���÷���
    friend ofstream &operator<<(ofstream &out, Score &c);

    friend ifstream &operator>>(ifstream &in, Score &c);
};


#endif //COURSEWORK_SCORE_H
