//
// Created by Admin on 2023/5/2.
//

#include <iomanip>
#include "StudentMenu.h"

void StudentMenu::menu() {
    cout << "ѧ�������� " << student_link.getNameById(id) << endl;
    cout << "1.��ѯ�ɼ�" << endl;
    cout << "2.ѡ��" << endl;
    cout << "3.�γ̲�ѯ" << endl;
    cout << "4.�γ�����" << endl;
    cout << "0.����" << endl;
    cout << "�����룺";
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
            cout << "�������" << endl;
    }

}

void StudentMenu::getScore() {
    cout << left << setw(10) << "�γ�" << left << setw(5) << "�ɼ�" << endl;
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
        cout << "δ�ҵ���" << endl;
        return;
    }
    sum /= i;
    cout << "�ܼƣ�" << i << "��" << endl;
    cout << "ƽ����" << setprecision(1) << sum << endl;
}

void StudentMenu::selectCourse() {
    cout << "������γ̱��:";
    string str;
    cin >> str;
    for (auto &s: scores) {
        if (s.getCourseId() == str) {
            cout << "�Ѿ�ѡ���ÿγ�" << endl;
            return;
        }
    }
    for (auto &s: courses) {
        if (s.getId() == str) {
            cout << "�γ����ƣ�" << course_link.getNameById(str) << "��ʦ��"
                 << teacher_link.getNameById(course_link.getTeacherId(str)) << endl;
        }
    }

}

void StudentMenu::findCourse() {

}

void StudentMenu::searchCourse() {

}
