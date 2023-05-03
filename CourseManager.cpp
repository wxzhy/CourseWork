//
// Created by Admin on 2023/5/3.
//

#include <iomanip>
#include "CourseManager.h"

void CourseManager::menu() {
    cout << "课程管理" << endl;
    cout << "1.查看全部课程" << endl;
    cout << "2.添加课程" << endl;
    cout << "3.删除课程" << endl;
    cout << "4.修改课程" << endl;
    cout << "请输入：";

    int op;
    cin >> op;
    switch (op) {
        case 1:
            showCourse();
            break;
        case 2:
            addCourse();
            break;
        case 3:
            deleteCourse();
            break;
        case 4:
            editCourse();
            break;
    }
}

void CourseManager::addCourse() {
    string str;
    cout << "输入课程编号：";
    cin >> str;
    if (course_link.ifExist(str)) {
        cout << "该编号已存在！" << endl;
        return;
    }
    Course c;
    c.setId(str);
    cout << "输入课程名称：";
    cin >> str;
    c.setName(str);
    cout << "输入课程教师工号：";
    cin >> str;
    c.setTeacherId(str);
    cout << "输入最大人数";
    int i;
    cin >> i;
    c.setMax(i);
}


void CourseManager::showCourse() {
    print(courses);

}

void CourseManager::print(Course c) {
    cout << "课程编号：" << c.getId() << endl;
    cout << "课程名称：" << c.getName() << endl;
    cout << "教师姓名：" << teacher_link.getNameById(c.getTeacherId()) << endl;
    cout << "当前人数：" << c.getCurrent() << endl;
    cout << "最大人数：" << c.getMax() << endl;
}

void CourseManager::print(vector<Course> c) {
    if (c.empty()) {
        cout << "未找到" << endl;
        return;
    }

    cout << "+------------+---------------+-----------------+-------+-------+" << endl;
    cout << "| " << setw(10) << "课程编号" << " | " << setw(15) << "课程名称" << " | "
         << setw(15) << "授课教师" << " | " << setw(5) << "当前人数" << " | "
         << setw(5) << "最大人数" << " |" << endl;
    cout << "+------------+---------------+-----------------+-------+-------+" << endl;

    for (auto &i: c) {
        cout << "| " << left << setw(10) << i.getId() << " | " << left << setw(15) << i.getName() << " | " << left
             << setw(15)
             << teacher_link.getNameById(i.getTeacherId()) << " | " << left << setw(5) << i.getCurrent() << " | "
             << left << setw(5) << i.getMax() << " |" << endl;
    }

    cout << "+------------+---------------+-----------------+-------+-------+" << endl;
    cout << "共有" << c.size() << "条结果" << endl;
}

void CourseManager::deleteCourse() {

}

void CourseManager::editCourse() {

}



