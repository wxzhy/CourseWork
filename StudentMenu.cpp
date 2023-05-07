//
// Created by Admin on 2023/5/2.
//

#include <iomanip>
#include "StudentMenu.h"
#include "CourseManager.h"

void StudentMenu::menu() {
    while (true) {
        //cout << "ѧ�������� " << student_link.getNameById(id) << endl;
        Display::Head("ѧ��ģ��           ѧ��������" + student_link.getNameById(id));
        cout << "     1.��ѯ�ɼ�" << endl;
        cout << "     2.ѡ��" << endl;
        cout << "     3.�γ̲�ѯ" << endl;
        cout << "     4.�γ�����" << endl;
        cout << "     0.�����ϼ��˵�" << endl;
        Display::Tail();
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
            case 0:
                return;
            default:
                cout << "�������" << endl;
        }
    }

}

void StudentMenu::getScore() {
    Display::Message();
    cout << "+-----------------+-------+" << endl;
    cout << "| " << left << setw(15) << "�γ�" << " | " << left << setw(5) << "�ɼ�" << " |" << endl;
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
        cout << "δ�ҵ���" << endl;
        return;
    }
    sum /= i;
    cout << "�ܼƣ�" << i << "��" << endl;
    cout << "ƽ����" << setprecision(3) << sum << endl;
}

void StudentMenu::selectCourse() {
    cout << "������γ̱��:";
    string str;
    cin >> str;
    for (auto &s: scores) {
        //ѧ���Ϳγ�ͬʱ�жϴ���
        if ((s.getCourseId() == str) && (s.getStudentId() == id)) {
            Display::Result();
            cout << "�Ѿ�ѡ���ÿγ�" << endl;
            return;
        }
    }
    for (auto &s: courses) {
        if (s.getId() == str) {
            Display::Message();
            cout << "�γ����ƣ�" << course_link.getNameById(str) << "��ʦ��"
                 << teacher_link.getNameById(course_link.getTeacherId(str)) << endl;
            if (s.getCurrent() >= s.getMax()) {
                cout << "�ÿγ���������" << endl;
                return;
            } else {
                score_link.add(id, str, 0.0);
                course_link.addCurrent(str);
                Display::Result();
                cout << "ѡ�γɹ���" << endl;
                return;
            }
        }
    }
    Display::Result();
    cout << "δ�ҵ��ÿγ�" << endl;

}

void StudentMenu::findCourse() {
    CourseManager().showCourse();
}

void StudentMenu::searchCourse() {
    CourseManager().search();

}
