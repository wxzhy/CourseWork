//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_TEACHERMENU_H
#define COURSEWORK_TEACHERMENU_H
#include <string>
#include <vector>
#include "Database.h"
#include "Display.h"

using namespace std;
class TeacherMenu : public Database, public Display {
    string id;
    vector<int> courseNums;//�洢�ý�ʦ�Ŀγ�
    vector<int> studentNums;//�洢�ÿγ̵�ѧ��
public:
    TeacherMenu(string id) : id(id) {}

    void menu();

    void getCourses();

    void courseMenu(int courseNum);//�γ̲˵�
    void addCourse();

    void addScore();

    void showCourse();

    void showScore();

    void changePassword();

    void AddScore();

    void editScore();

    void calculate();

    void sortByScore();

    void sortById();
};


#endif //COURSEWORK_TEACHERMENU_H
