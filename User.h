//
// Created by Wxyz on 2023/4/2.
//

#ifndef COURSEWORK_USER_H
#define COURSEWORK_USER_H

#include <string>

using namespace std;

class User {//User类的声明
protected:
    string id, name, password, telephone;//号码，姓名，密码，电话
    string sex;//性别
public:
    User() = default;

    User(string &id, string &name, string &sex) : id(id), name(name), sex(sex), password(id) {};

    string getId() const { return id; }//获得编号
    void setId(string &id) { this->id = id; }//设置编号
    string getName() { return name; }//获得姓名
    void setName(string &name) { this->name = name; }//设置姓名
    string getSex() { return sex; }//获得性别
    void setSex(string &sex) { this->sex = sex; }//设置性别
    void setPassword(string &password) { this->password = password; }//设置密码
    bool checkPassword(string pass);//检查密码
};


#endif //COURSEWORK_USER_H
