//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_COURSE_H
#define COURSEWORK_COURSE_H

#include <string>

using namespace std;

class Course {//Course�������
    string id, teacherId, name;//��ʦid,���ƣ����
    int current, max;//��ǰ�������������
public:
    Course() { current = 0; }//���캯��
    Course(string id, string teacherId, string name, int max) : id(id), teacherId(teacherId), name(name), max(max),
                                                                current(0) {}

    string getId() { return id; }//��ñ��
    void setId(string &id) { this->id = id; }//���ñ��
    string getTeacherId() { return teacherId; }//��ý�ʦ���
    void setTeacherId(string &tid) { this->teacherId = tid; }//���ý�ʦ���
    string getName() { return name; }//�������
    void setName(string &name) { this->name = name; }//��������
    int getCurrent() { return current; }//�������
    void addCurrent() { current++; }//��������
    int getMax() { return max; }//����������
    void setMax(int max) { this->max = max; }//���������ʶ
    friend ofstream &operator<<(ofstream &out, Course &c);//���ء�������
    friend ifstream &operator>>(ifstream &in, Course &c);//���ء�������
};


#endif //COURSEWORK_COURSE_H
