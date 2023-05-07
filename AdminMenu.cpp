//
// Created by Admin on 2023/5/2.
//

#include "AdminMenu.h"
#include "StudentManager.h"
#include "TeacherManager.h"
#include "CourseManager.h"
#include "ScoreManager.h"

void AdminMenu::menu() {
    while (true) {
        Display::Head(">>管理模块");
        cout << "     1.学生管理" << endl;
        cout << "     2.教师管理" << endl;
        cout << "     3.课程管理" << endl;
        cout << "     4.成绩管理" << endl;
        cout << "     0.返回上级菜单" << endl;
        Display::Tail();
        cout << "请输入：";
        int op;
        cin >> op;
        switch (op) {
            case 0:
                return;
            case 1: {
                StudentManager().menu();
                break;
            }
            case 2: {
                TeacherManager().menu();
                break;
            }
            case 3: {
                CourseManager().menu();
                break;
            }
            case 4: {
                ScoreManager().menu();
                break;
            }
            default:
                cout << "输入错误" << endl;
        }
    }


}
