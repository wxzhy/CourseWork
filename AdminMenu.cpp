//
// Created by Admin on 2023/5/2.
//

#include "AdminMenu.h"
#include "StudentManager.h"
#include "TeacherManager.h"
#include "CourseManager.h"
#include "ScoreManager.h"

void AdminMenu::menu() {
    Head("管理模块");
    cout << "1.学生管理" << endl;
    cout << "2.教师管理" << endl;
    cout << "3.课程管理" << endl;
    cout << "4.成绩管理" << endl;
    cout << "0.退出" << endl;
    int op;
    cin >> op;
    switch (op) {
        case 0:
            return;
        case 1: {
            StudentManager m;
            m.menu();
            break;
        }
        case 2: {
            TeacherManager m;
            m.menu();
        }
        case 3: {
            CourseManager m;
            m.menu();
        }
        case 4: {
            ScoreManager m;
            m.menu();
        }
    }


}
