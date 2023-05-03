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
    cout << "课程名称： " << courses[courseNum].getName() << endl;
    cout << "1.查看学生成绩" << endl;
    cout << "2.录入学生成绩" << endl;
    cout << "3.修改学生成绩" << endl;
    cout << "4.删除学生成绩" << endl;
    cout << "5.统计信息" << endl;
    cout << "0.退出" << endl;
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
    cout << "姓名： " << teacher_link.getNameById(id);
    getCourses();
    if (courseNums.empty()) {
        cout << "无课程！" << endl;
    } else
        cout << "课程信息：" << endl;
    cout << left << setw(10) << "课程编号" << left << setw(15) << "课程名称" << setw(5) << "人数" << setw(5) << "最大"
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
