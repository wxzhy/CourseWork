//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_DISPLAY_H
#define COURSEWORK_DISPLAY_H


#include "Database.h"
#include<iostream>
#include <string>

using namespace std;

class Display {
public:
    void start();

    void Head(); //菜单框头
    
    void Head(string s);

    void Head(string s1, string s2);

    void Tail();//菜单框尾

    static void Result(string s);//执行结果

    void Line();

    void boldLine();

    string PassRead();
};


#endif //COURSEWORK_DISPLAY_H
