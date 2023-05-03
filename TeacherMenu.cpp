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
    studentNums = score_link.getScoreNumByCourseId(courses[courseNum].getId());
    cout << "1.查看学生成绩" << endl;
    cout << "2.录入学生成绩" << endl;
    cout << "3.修改学生成绩" << endl;
    cout << "4.统计信息" << endl;
    cout << "0.退出" << endl;
    int op;
    cin>>op;
    switch (op) {
        case 1:
            showScore();
            break;
        case 2:
            addScore();
            break;
        case 3:
            editScore();
            break;
            case 4:
                calculate();
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
    } else {
        int n = 0;
        cout << "课程信息：" << endl;
        cout << left << setw(5) << "序号" << left << setw(10) << "课程编号" << left << setw(15) << "课程名称" << setw(5)
             << "人数" << setw(5) << "最大"
             << endl;

        for (auto &s: courseNums) {
            cout << left << setw(5) << (++n) << left << setw(10) << courses[s].getId() << left << setw(15)
                 << courses[s].getName() << setw(5)
                 << courses[s].getCurrent() << setw(5) << courses[s].getMax()
                 << endl;
        }
        cout << "请选择要操作的课程序号：";
        int choice;
        cin >> choice;
        if (choice <= 0 || choice > courseNums.size()) {
            cout << "输入错误！" << endl;
        } else {
            courseMenu(courseNums[choice - 1]);
        }
    }

}

void TeacherMenu::showCourse() {

}

void TeacherMenu::showScore() {
    if (studentNums.empty()) {
        cout << "未找到" << endl;
        return;
    }
    int n = 0;
    cout << left << setw(10) << "学号" << left << setw(10) << "姓名" << left << setw(5) << "成绩" << endl;
    Line();
    for (auto &i: studentNums) {
        cout << left << setw(10) << scores[studentNums[i]].getId() << left << setw(10)
             << student_link.getNameById(scores[studentNums[i]].getId()) << left << setprecision(1) << setw(5)
             << scores[studentNums[i]].getValue() << endl;
        n++;
        if (n % 20 == 0)
            system("pause");
    }
        boldLine();
        cout << "共有" << n << "条结果" << endl;

    }



void TeacherMenu::addScore() {
    for (auto &i: studentNums) {
        cout << "学号：" << scores[studentNums[i]].getId()<<"姓名："<<student_link.getNameById(scores[studentNums[i]].getId())<<endl;
        cout<<"输入成绩：";
        float score;
        cin>>score;
        scores[studentNums[i]].setValue(score);
    }
}

void TeacherMenu::editScore() {

}

void TeacherMenu::calculate() {
    float total=0.0;

    for(auto &i: studentNums) {
        total+=scores[studentNums[i]].getValue();
    }
    total/=studentNums.size();
    cout<<"平均分："<<setprecision(1)<<total<<endl;

}
