//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_LINK_H
#define COURSEWORK_LINK_H

#include "Student.h"
#include <algorithm>
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

    virtual void add(T node);//���
    virtual void del(string id);//��IDɾ��
    vector<T> findByName(string name);//�����Ʋ���
    void reverse();//��ת
    T find(string id);//��id����
    void load(string filename);//���ļ�����
    void save(string filename);//���浽�ļ�
    string getNameById(string id);//����id��ѯ����
    vector<string> getIdByName(string name);//���ݲ���������ѯid
    virtual void sortById();//����id����
    bool ifExist(string id);//id�Ƿ��ظ�
    void erase(T node);

    int getNumById(string id);
};

template<class T>
void Link<T>::erase(T node) {
    link.erase(node);

}

template<class T>
bool Link<T>::ifExist(string id) {
    for (auto &t: link) {
        if (t.getId() == id) {
            return true;
        }
    }
    return false;
}

template<class T>
void Link<T>::sortById() {
    sort(link.begin(), link.end(),
         [](T &s1, T &s2) { return s1.getId() < s2.getId(); });
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
        cout << filename << "д��ʧ��" << endl;
    //Result("filename"+"д��ʧ��");
    for (auto &n: link)
        file << n;
    file.close();
}

template<class T>
void Link<T>::load(string filename) {
    ifstream file(filename);
    if (file.fail()) {
        cout << filename << "��ʧ��" << endl;
        cout << "�Ƿ񴴽�" << filename << "(Yes/No):";
        string str;
        cin >> str;
        if (str == "Yes") {
            ofstream out(filename);
            out.close();
            cout << "�����ɹ�" << endl;
            file.close();
            file.open(filename);
        } else {
            return;
        }
    }
    T node;
    file >> node;
    while (!file.eof()) {
        add(node);
        file >> node;
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
        if (n.getName().find(name) != -1)
            result.push_back(n);
    }
    return result;
}

template<class T>
Link<T>::Link() {
}

template<class T>
void Link<T>::del(string id) {
    for (auto it = link.begin(); it != link.end(); it++) {
        if (it->getId() == id) {
            link.erase(it);
            break;
        }
    }
}

template<class T>
void Link<T>::add(T node) {
    if (ifExist(node.getId()))
        return;
    link.push_back(node);
}

template<class T>
int Link<T>::getNumById(string id) {
    for (auto it = link.begin(); it != link.end(); ++it)
        if (it->getId() == id)
            return it - link.begin();
    return -1;
}

#endif //COURSEWORK_LINK_H
