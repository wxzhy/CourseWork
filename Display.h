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

    void Head();

    void Head(string s);

    void Line();

    void boldLine();

    string PassRead();
};


#endif //COURSEWORK_DISPLAY_H