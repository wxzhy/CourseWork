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

class Student : public User {
    string prof, grade;//רҵ���꼶
//    vector<score> s;
public:
    Student() = default;//���캯��
    Student(string id, string name, string sex, string prof, string grade) : User(id, name, sex), prof(prof),
                                                                             grade(grade) {}

    string getProf() { return prof; }   //���רҵ
    void setProf(string &prof) { this->prof = prof; }//����רҵ
    string getGrade() { return grade; }//����꼶
    void setGrade(string &grade) { this->grade = grade; }//�����꼶
    friend ofstream &operator<<(ofstream &out, Student &c);//���ء�������
    friend ifstream &operator>>(ifstream &in, Student &c);//���ء�������
};


#endif //COURSEWORK_STUDENT_H
