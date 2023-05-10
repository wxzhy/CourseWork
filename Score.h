//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_SCORE_H
#define COURSEWORK_SCORE_H

#include <string>

using namespace std;

class Score {//Score�������
    string studentId, courseId;//ѧ��id,�γ�id
    float value;//����
public:
    Score() {}//���캯��
    Score(string studentId, string courseId, float value) : studentId(studentId), courseId(courseId), value(value) {}

    string getId() { return studentId; }

    string getStudentId() { return studentId; }//���ѧ��id
    void setStudentId(string &s) { studentId = s; }//����ѧ��id
    string getCourseId() { return courseId; }//��ÿγ�id
    void setCourseId(string &s) { courseId = s; }//���ÿγ�id
    float getValue() { return value; }//��÷���
    void setValue(float value) { this->value = value; }//���÷���
    friend ofstream &operator<<(ofstream &out, Score &c);//����<<
    friend ifstream &operator>>(ifstream &in, Score &c);//����>>
};


#endif //COURSEWORK_SCORE_H
