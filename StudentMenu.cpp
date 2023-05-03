//
// Created by Admin on 2023/5/2.
//

#include <iomanip>
#include "StudentMenu.h"

void StudentMenu::menu() {
    cout << "学生姓名： " << student_link.getNameById(id) << endl;
    cout << "1.查询成绩" << endl;
    cout << "2.选课" << endl;
    cout << "3.课程查询" << endl;
    cout << "4.课程搜索" << endl;
    cout << "0.返回" << endl;
    cout << "请输入：";
    int op;
    cin >> op;
    switch (op) {
        case 1:
            getScore();
            break;
        case 2:
            selectCourse();
            break;
        case 3:
            findCourse();
            break;
        case 4:
            searchCourse();
            break;
        default:
            cout << "输入错误！" << endl;
    }

}

void StudentMenu::getScore() {
    cout << left << setw(10) << "课程" << left << setw(5) << "成绩" << endl;
    int i = 0;
    float sum = 0.0;
    for (auto &s: scores) {
        if (s.getStudentId() == id) {
            cout << left << setw(10) << course_link.getNameById(s.getCourseId()) << left << setw(5) << setprecision(1)
                 << s.getValue() << endl;
            sum += s.getValue();
            i++;
            if (i % 20 == 0)
                system("pause");
        }
    }
    if (i <= 0) {
        cout << "未找到！" << endl;
        return;
    }
    sum /= i;
    cout << "总计：" << i << "门" << endl;
    cout << "平均分" << setprecision(1) << sum << endl;
}

void StudentMenu::selectCourse() {
    cout << "请输入课程编号:";
    string str;
    cin >> str;
    for (auto &s: scores) {
        if (s.getCourseId() == str) {
            cout << "已经选过该课程" << endl;
            return;
        }
    }
    for (auto &s: courses) {
        if (s.getId() == str) {
            cout << "课程名称：" << course_link.getNameById(str) << "教师："
                 << teacher_link.getNameById(course_link.getTeacherId(str)) << endl;
        }
    }

}

void StudentMenu::findCourse() {

}

void StudentMenu::searchCourse() {

}
