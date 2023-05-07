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
        Display::Head(">>����ģ��");
        cout << "     1.ѧ������" << endl;
        cout << "     2.��ʦ����" << endl;
        cout << "     3.�γ̹���" << endl;
        cout << "     4.�ɼ�����" << endl;
        cout << "     0.�����ϼ��˵�" << endl;
        Display::Tail();
        cout << "�����룺";
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
                cout << "�������" << endl;
        }
    }


}
