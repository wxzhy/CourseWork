//
// Created by Admin on 2023/5/3.
//

#ifndef COURSEWORK_SCOREMANAGER_H
#define COURSEWORK_SCOREMANAGER_H


#include "Display.h"
#include "Database.h"
#include <iostream>

using namespace std;

class ScoreManager : public Database, public Display {
public:
    void menu();

    void addScore();

    void editScore();

    void delScore();

    void showAll();

    void print(vector<Score> s);

    void del();

    void queryByCourse();
};


#endif //COURSEWORK_SCOREMANAGER_H
