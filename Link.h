//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_LINK_H
#define COURSEWORK_LINK_H

#include "Student.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

template<class T>
class Link {

public:
    vector<T> link;//向量
    Link();

    void add(T node);//添加
    void del(string id);//按ID删除
    vector<T> findByName(string name);//按名称查找
    void reverse();//反转
    T find(string id);//按id查找
    void load(string filename);//从文件加载
    void save(string filename);//保存到文件
    string getNameById(string id);//根据id查询名称
    vector<string> getIdByName(string name);//根据部分姓名查询id
    void sort();//根据id排序

};

template<class T>
void Link<T>::sort() {
    sort(link.begin(), link.end(), [](const T &lhs, const T &rhs) {
        return lhs.getId() > rhs.getId();
    });
}

template<class T>
bool compare(T node1, T node2) {
    if (node1.getId() > node2.getId()) {
        return true;
    }
    return false;
}

template<class T>
vector<string> Link<T>::getIdByName(string name) {
    vector<string> ids;
    for (auto s: link)
        if (s.getName().find(name) != -1)
            ids.push_back(s.getId());
    return ids;

}

template<class T>
string Link<T>::getNameById(string id) {
    for (auto &s: link) {
        if (s.getId() == id)
            return s.getName();
    }
    return "";//未找到返回空
}

template<class T>
void Link<T>::save(string filename) {
    ofstream file(filename);
    if (file.fail())
        cout << "写入失败";
    for (auto &n: link)
        file << n;
    file.close();
    cout << "写入成功";
}

template<class T>
void Link<T>::load(string filename) {
    ifstream file(filename);
    if (file.fail())
        cout << "打开失败";
    T node;
    while (!file.eof()) {
        file >> node;
        add(node);
    }
    file.close();
}

template<class T>
T Link<T>::find(string id) {
    for (auto &n: link)
        if (n.id == id)
            return n;
}

template<class T>
void Link<T>::reverse() {
    link.reverse();
}

template<class T>
vector<T> Link<T>::findByName(string name) {
    vector<T> result;
    for (auto &n: link) {
        if (n.name.find(name) != -1)
            result.push_back(n);
    }
    return result;
}

template<class T>
Link<T>::Link() {
}

template<class T>
void Link<T>::del(string id) {
    for (auto &p: link) {
        if (p->id == id) {
            link.erase(p);
            break;
        }
    }
}

template<class T>
void Link<T>::add(T node) {
    link.push_back(node);
}


#endif //COURSEWORK_LINK_H
