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
    vector<T> link;//����
    Link();

    void add(T node);//���
    void del(string id);//��IDɾ��
    vector<T> findByName(string name);//�����Ʋ���
    void reverse();//��ת
    T find(string id);//��id����
    void load(string filename);//���ļ�����
    void save(string filename);//���浽�ļ�
    string getNameById(string id);//����id��ѯ����
    vector<string> getIdByName(string name);//���ݲ���������ѯid
    void sort();//����id����

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
    return "";//δ�ҵ����ؿ�
}

template<class T>
void Link<T>::save(string filename) {
    ofstream file(filename);
    if (file.fail())
        cout << "д��ʧ��";
    for (auto &n: link)
        file << n;
    file.close();
    cout << "д��ɹ�";
}

template<class T>
void Link<T>::load(string filename) {
    ifstream file(filename);
    if (file.fail())
        cout << "��ʧ��";
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
