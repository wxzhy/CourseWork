//
// Created by Admin on 2023/5/2.
//

#include "AdminMenu.h"
#include "StudentManager.h"
#include "TeacherManager.h"
#include "CourseManager.h"
#include "ScoreManager.h"

void AdminMenu::menu() {
    Head("����ģ��");
    cout << "1.ѧ������" << endl;
    cout << "2.��ʦ����" << endl;
    cout << "3.�γ̹���" << endl;
    cout << "4.�ɼ�����" << endl;
    cout << "0.�˳�" << endl;
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
