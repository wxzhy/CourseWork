//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_COURSE_H
#define COURSEWORK_COURSE_H

#include <string>

using namespace std;

class Course {
    string id, teacherId, name, desc;//��ʦid,���ƣ����
public:
    string getId() { return id; }//��ñ��
    void setId(string &id) { this->id = id; }//���ñ��
    string getTid() { return teacherId; }//��ý�ʦ���
    void setTid(string &tid) { this->teacherId = tid; }//���ý�ʦ���
    string getName() { return name; }//�������
    void setName(string &name) { this->name = name; }//��������
    string getDesc() { return desc; }//��ü��
    void setDesc(string &desc) { this->desc = desc; }//���ü��
    friend ofstream &operator<<(ofstream &out, Course &c);//���ء�������
    friend ifstream &operator>>(ifstream &in, Course &c);//���ء�������

};


#endif //COURSEWORK_COURSE_H
