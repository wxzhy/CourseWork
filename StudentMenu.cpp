//
// Created by Admin on 2023/5/2.
//

#include <iomanip>
#include "StudentMenu.h"
#include "CourseManager.h"

void StudentMenu::menu() {
    while (true) {
        //cout << "学生姓名： " << student_link.getNameById(id) << endl;
        Display::Head("学生模块           学生姓名：" + student_link.getNameById(id));
        cout << "     1.查询成绩" << endl;
        cout << "     2.选课" << endl;
        cout << "     3.课程查询" << endl;
        cout << "     4.课程搜索" << endl;
        cout << "     0.返回上级菜单" << endl;
        Display::Tail();
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
            case 0:
                return;
            default:
                cout << "输入错误！" << endl;
        }
    }

}

void StudentMenu::getScore() {
    Display::Message();
    cout << "+-----------------+-------+" << endl;
    cout << "| " << left << setw(15) << "课程" << " | " << left << setw(5) << "成绩" << " |" << endl;
    cout << "+-----------------+-------+" << endl;
    int i = 0;
    float sum = 0.0;
    for (auto &s: scores) {
        if (s.getStudentId() == id) {
            cout << "| " << left << setw(15) << course_link.getNameById(s.getCourseId()) << " | " << left << setw(5)
                 << setprecision(3)
                 << s.getValue() << " |" << endl;
            sum += s.getValue();
            i++;
            if (i % 20 == 0)
                system("pause");
        }
    }
    cout << "+-----------------+-------+" << endl;
    if (i <= 0) {
        Display::Result();
        cout << "未找到！" << endl;
        return;
    }
    sum /= i;
    cout << "总计：" << i << "门" << endl;
    cout << "平均分" << setprecision(3) << sum << endl;
}

void StudentMenu::selectCourse() {
    cout << "请输入课程编号:";
    string str;
    cin >> str;
    for (auto &s: scores) {
        //学生和课程同时判断存在
        if ((s.getCourseId() == str) && (s.getStudentId() == id)) {
            Display::Result();
            cout << "已经选过该课程" << endl;
            return;
        }
    }
    for (auto &s: courses) {
        if (s.getId() == str) {
            Display::Message();
            cout << "课程名称：" << course_link.getNameById(str) << "教师："
                 << teacher_link.getNameById(course_link.getTeacherId(str)) << endl;
            if (s.getCurrent() >= s.getMax()) {
                cout << "该课程人数已满" << endl;
                return;
            } else {
                score_link.add(id, str, 0.0);
                course_link.addCurrent(str);
                Display::Result();
                cout << "选课成功！" << endl;
                return;
            }
        }
    }
    Display::Result();
    cout << "未找到该课程" << endl;

}

void StudentMenu::findCourse() {
    CourseManager().showCourse();
}

void StudentMenu::searchCourse() {
    CourseManager().search();

}
