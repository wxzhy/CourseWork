//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_USER_H
#define COURSEWORK_USER_H

#include <string>

using namespace std;

class User {//User�������
protected:
    string id, name, password, telephone;//���룬���������룬�绰
    string sex;//�Ա�
public:
    User() = default;

    User(string &id, string &name, string &sex) : id(id), name(name), sex(sex), password(id) {};

    string getId() const { return id; }//��ñ��
    void setId(string &id) { this->id = id; }//���ñ��
    string getName() { return name; }//�������
    void setName(string &name) { this->name = name; }//��������
    string getSex() { return sex; }//����Ա�
    void setSex(string &sex) { this->sex = sex; }//�����Ա�
    void setPassword(string &password) { this->password = password; }//��������
    bool checkPassword(string pass);//�������
};


#endif //COURSEWORK_USER_H
