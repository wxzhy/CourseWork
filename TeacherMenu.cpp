//
// Created by Admin on 2023/5/2.
//

#include "TeacherMenu.h"
#include <iostream>
#include <iomanip>
#include "Database.h"

using namespace std;

void TeacherMenu::addCourse() {

}

void TeacherMenu::courseMenu(int courseNum) {
    cout << "�γ����ƣ� " << courses[courseNum].getName() << endl;
    cout << "1.�鿴ѧ���ɼ�" << endl;
    cout << "2.¼��ѧ���ɼ�" << endl;
    cout << "3.�޸�ѧ���ɼ�" << endl;
    cout << "4.ɾ��ѧ���ɼ�" << endl;
    cout << "5.ͳ����Ϣ" << endl;
    cout << "0.�˳�" << endl;
    int op;
    switch (op) {
        case 1:
            showScore();
            break;
        case 2:
            addScore();
            break;
    }
}

void TeacherMenu::getCourses() {
    courseNums = course_link.getNumByTeacherId(id);

}

void TeacherMenu::AddScore() {


}

void TeacherMenu::menu() {
    cout << "������ " << teacher_link.getNameById(id);
    getCourses();
    if (courseNums.empty()) {
        cout << "�޿γ̣�" << endl;
    } else
        cout << "�γ���Ϣ��" << endl;
    cout << left << setw(10) << "�γ̱��" << left << setw(15) << "�γ�����" << setw(5) << "����" << setw(5) << "���"
         << endl;

    for (auto &s: courseNums) {
        cout << left << setw(10) << courses[s].getId() << left << setw(15) << courses[s].getName() << setw(5)
             << courses[s].getCurrent() << setw(5) << courses[s].getMax()
             << endl;
    }

}

void TeacherMenu::showCourse() {

}

void TeacherMenu::showScore() {

}

void TeacherMenu::addScore() {

}
