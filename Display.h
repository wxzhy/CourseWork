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

    static void Head(); //菜单框头

    static void Head(string s);

    static void Head(string s1, string s2);

    static void Tail();//菜单框尾

    static void Result();//执行结果分割线

    static void Result(string s);//执行结果

    static void Message();//信息提示分割线

    static void Message(string s);//信息提示

    static void Line();

    static void boldLine();

    static string PassRead();
};


#endif //COURSEWORK_DISPLAY_H
