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
    vector<T> link;

public:
    Link();
    void add(T node);
    void del(string id);
    vector<T> findByName(string name);
    void reverse();
    T find(string id);
    void load(string filename);
    void save(string filename);

};

template<class T>
void Link<T>::save(string filename) {
    ofstream file(filename);
    if(file.fail())
        cout<<"写入失败";
    for(auto& n:link)
        file<<n;
    file.close();
    cout<<"写入成功";
}

template<class T>
void Link<T>::load(string filename) {
    ifstream file(filename);
    if(file.fail())
        cout<<"打开失败";
    T node;
    while(!file.eof()) {
        file>>node;
        add(node);
    }
    file.close();
}

template<class T>
T Link<T>::find(string id) {
    for(auto& n : link)
        if(n.id ==id)
            return n;
}

template<class T>
void Link<T>::reverse() {
    link.reverse();
}

template<class T>
vector<T> Link<T>::findByName(string name) {
    vector<T> result;
    for(auto& n:link) {
        if(n.name.find(name)!=-1)
            result.push_back(n);
    }
    return result;
}

template<class T>
Link<T>::Link() {
}

template<class T>
void Link<T>::del(string id) {
    for(auto &p : link){
        if(p->id==id){
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
