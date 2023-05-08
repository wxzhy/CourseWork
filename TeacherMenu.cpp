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
    Display::Head(">>教师模块                 课程名称：" + courses[courseNum].getName());
    //cout << "课程名称： " << courses[courseNum].getName() << endl;
    studentNums = score_link.getScoreNumByCourseId(courses[courseNum].getId());
    cout << "     1.查看学生成绩" << endl;
    cout << "     2.录入学生成绩" << endl;
    cout << "     3.修改学生成绩" << endl;
    cout << "     4.统计信息" << endl;
    cout << "     5.按成绩排序" << endl;
    cout << "     6.按学号排序" << endl;
    cout << "     7.重新选择课程" << endl;
    cout << "     0.返回上级菜单" << endl;
    Display::Tail();
    cout << "请输入：";
    int op;
    cin >> op;
    switch (op) {
        case 1:
            showScore(courseNum);
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
        case 5:
            sortByScore();
            break;
        case 6:
            sortById();
            break;
        case 7:
            choiced = 0;
            break;
        case 0:
            choiced = -1;
            break;
        default:
            return;

    }
}

void TeacherMenu::getCourses() {
    courseNums = course_link.getNumByTeacherId(id);

}

void TeacherMenu::AddScore() {


}

void TeacherMenu::menu() {
    while (true) {
        if (choiced == 0) {
            //重新选择操作课程

            Display::Message();
            cout << "姓名： " << teacher_link.getNameById(id) << endl;
            getCourses();
            if (courseNums.empty()) {
                Display::Result();
                cout << "无课程！" << endl;
                return;
            } else {
                int n = 0;
                //cout << "课程信息：" << endl;
                Display::Message("课程信息");
                //cout << left << setw(5) << "序号" << left << setw(10) << "课程编号" << left << setw(15) << "课程名称"
                //     << setw(5)
                //     << "人数" << setw(5) << "最大"
                //     << endl;
                cout << "+-------+------------+-----------------+-----------------+----------+----------+" << endl;
                cout << "| " << left << setw(5) << "序号" << " | " << setw(10) << "课程编号" << " | " << setw(15)
                     << "课程名称" << " | "
                     << setw(15) << "授课教师" << " | " << setw(8) << "当前人数" << " | "
                     << setw(8) << "最大人数" << " |" << endl;
                cout << "+-------+------------+-----------------+-----------------+----------+----------+" << endl;
                for (auto &s: courseNums) {
                    //    cout << left << setw(5) << (++n) << left << setw(10) << courses[s].getId() << left << setw(15)
                    //         << courses[s].getName() << setw(5)
                    //         << courses[s].getCurrent() << setw(5) << courses[s].getMax()
                    //         << endl;
                    cout << "| " << left << setw(5) << (++n) << " | " << setw(10) << courses[s].getId() << " | "
                         << setw(15) << courses[s].getName() << " | "
                         << setw(15) << teacher_link.getNameById(id) << " | " << setw(8) << courses[s].getCurrent()
                         << " | "
                         << setw(8) << courses[s].getMax() << " |" << endl;
                }

                cout << "+-------+------------+-----------------+-----------------+----------+----------+" << endl;
                cout << "共有" << courseNums.size() << "条结果" << endl;

                cout << "请选择要操作的课程序号：";
                int choice;
                cin >> choice;
                if (choice <= 0 || choice > courseNums.size()) {
                    //cout << "输入错误！" << endl;
                    return;
                } else {
                    choiced = choice;
                    courseMenu(courseNums[choiced - 1]);
                }
            }
        } else if (choiced == -1) {
            //退回上级
            break;
        } else {
            //已经选择课程
            courseMenu(courseNums[choiced - 1]);
        }
    }

}

void TeacherMenu::showCourse() {

}

void TeacherMenu::showScore(int courseNum) {
    if (studentNums.empty()) {
        Display::Result();
        cout << "未找到" << endl;
        return;
    }
    int n = 0;
    Display::Message();
    cout << "+------------+------------+-----------------+-------+" << endl;
    cout << "| " << left << setw(10) << "学号" << " | " << left << setw(10) << "姓名" << " | " << setw(15) << "课程名称"
         << " | " << left << setw(5) << "成绩" << " |" << endl;
    cout << "+------------+------------+-----------------+-------+" << endl;
    for (auto &i: studentNums) {
        //改正错误,循环内部不应该有studentNums
        //cout << "| " << left << setw(10) << scores[studentNums[i]].getId() << " | "
        // << left << setw(10) << student_link.getNameById(scores[studentNums[i]].getId()) << " | "
        // << setw(15) << courses[courseNum].getName() << " | "
        // << left << setprecision(3) << setw(5) << scores[studentNums[i]].getValue() << " |" << endl;
        cout << "| " << left << setw(10) << scores[i].getId() << " | ";
        cout << left << setw(10) << student_link.getNameById(scores[i].getId()) << " | ";
        cout << setw(15) << courses[courseNum].getName() << " | ";
        cout << left << setprecision(3) << setw(5) << scores[i].getValue() << " |" << endl;

        n++;
        if (n % 20 == 0)
            system("pause>nul");
    }
    cout << "+------------+------------+-----------------+-------+" << endl;
    cout << "共有" << n << "条结果" << endl;
    system("pause>nul");

}


void TeacherMenu::addScore() {
    for (auto &i: studentNums) {
        //cout << "学号：" << scores[studentNums[i]].getId() << "姓名："
        //     << student_link.getNameById(scores[studentNums[i]].getId()) << endl;
        cout << "学号：" << scores[i].getId() << "姓名："
             << student_link.getNameById(scores[i].getId()) << endl;
        cout << "输入成绩：";
        float score;
        cin >> score;
        //scores[studentNums[i]].setValue(score);
        scores[i].setValue(score);
    }
}

void TeacherMenu::editScore() {
    cout << "输入学号：";
    string studentId;
    cin >> studentId;
    for (auto &i: studentNums) {
        if (scores[i].getId() == studentId) {
            cout << "原成绩：" << endl;
            cout << "学号：" << scores[i].getId() << "姓名："
                 << student_link.getNameById(scores[i].getId()) << "成绩：" << setprecision(3) << scores[i].getValue()
                 << endl;
            cout << "输入新的成绩";
            float s;
            cin >> s;
            scores[i].setValue(s);
            cout << "修改成功" << endl;
            return;
        }
        cout << "未找到该学生" << endl;
    }
}

void TeacherMenu::calculate() {
    float total = 0.0;

    for (auto &i: studentNums) {
        //total += scores[studentNums[i]].getValue();
        total += scores[i].getValue();
    }
    total /= studentNums.size();
    Display::Message();
    cout << "总人数：" << studentNums.size() << endl;
    cout << "平均分：" << setprecision(3) << total << endl;

}

void TeacherMenu::changePassword() {
    cout << "输入密码：";

}

void TeacherMenu::sortByScore() {
    score_link.sortByValue();
    Display::Result();
    cout << "已排序" << endl;

}

void TeacherMenu::sortById() {
    score_link.sortByStudentId();
    Display::Result();
    cout << "已排序" << endl;

}
