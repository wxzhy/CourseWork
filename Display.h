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

    static void Head(); //�˵���ͷ

    static void Head(string s);

    static void Head(string s1, string s2);

    static void Tail();//�˵���β

    static void Result();//ִ�н���ָ���

    static void Result(string s);//ִ�н��

    static void Message();//��Ϣ��ʾ�ָ���

    static void Message(string s);//��Ϣ��ʾ

    static void Line();

    static void boldLine();

    static string PassRead();
};


#endif //COURSEWORK_DISPLAY_H
