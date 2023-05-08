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
    Display::Head(">>��ʦģ��                 �γ����ƣ�" + courses[courseNum].getName());
    //cout << "�γ����ƣ� " << courses[courseNum].getName() << endl;
    studentNums = score_link.getScoreNumByCourseId(courses[courseNum].getId());
    cout << "     1.�鿴ѧ���ɼ�" << endl;
    cout << "     2.¼��ѧ���ɼ�" << endl;
    cout << "     3.�޸�ѧ���ɼ�" << endl;
    cout << "     4.ͳ����Ϣ" << endl;
    cout << "     5.���ɼ�����" << endl;
    cout << "     6.��ѧ������" << endl;
    cout << "     7.����ѡ��γ�" << endl;
    cout << "     0.�����ϼ��˵�" << endl;
    Display::Tail();
    cout << "�����룺";
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
            //����ѡ������γ�

            Display::Message();
            cout << "������ " << teacher_link.getNameById(id) << endl;
            getCourses();
            if (courseNums.empty()) {
                Display::Result();
                cout << "�޿γ̣�" << endl;
                return;
            } else {
                int n = 0;
                //cout << "�γ���Ϣ��" << endl;
                Display::Message("�γ���Ϣ");
                //cout << left << setw(5) << "���" << left << setw(10) << "�γ̱��" << left << setw(15) << "�γ�����"
                //     << setw(5)
                //     << "����" << setw(5) << "���"
                //     << endl;
                cout << "+-------+------------+-----------------+-----------------+----------+----------+" << endl;
                cout << "| " << left << setw(5) << "���" << " | " << setw(10) << "�γ̱��" << " | " << setw(15)
                     << "�γ�����" << " | "
                     << setw(15) << "�ڿν�ʦ" << " | " << setw(8) << "��ǰ����" << " | "
                     << setw(8) << "�������" << " |" << endl;
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
                cout << "����" << courseNums.size() << "�����" << endl;

                cout << "��ѡ��Ҫ�����Ŀγ���ţ�";
                int choice;
                cin >> choice;
                if (choice <= 0 || choice > courseNums.size()) {
                    //cout << "�������" << endl;
                    return;
                } else {
                    choiced = choice;
                    courseMenu(courseNums[choiced - 1]);
                }
            }
        } else if (choiced == -1) {
            //�˻��ϼ�
            break;
        } else {
            //�Ѿ�ѡ��γ�
            courseMenu(courseNums[choiced - 1]);
        }
    }

}

void TeacherMenu::showCourse() {

}

void TeacherMenu::showScore(int courseNum) {
    if (studentNums.empty()) {
        Display::Result();
        cout << "δ�ҵ�" << endl;
        return;
    }
    int n = 0;
    Display::Message();
    cout << "+------------+------------+-----------------+-------+" << endl;
    cout << "| " << left << setw(10) << "ѧ��" << " | " << left << setw(10) << "����" << " | " << setw(15) << "�γ�����"
         << " | " << left << setw(5) << "�ɼ�" << " |" << endl;
    cout << "+------------+------------+-----------------+-------+" << endl;
    for (auto &i: studentNums) {
        //��������,ѭ���ڲ���Ӧ����studentNums
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
    cout << "����" << n << "�����" << endl;
    system("pause>nul");

}


void TeacherMenu::addScore() {
    for (auto &i: studentNums) {
        //cout << "ѧ�ţ�" << scores[studentNums[i]].getId() << "������"
        //     << student_link.getNameById(scores[studentNums[i]].getId()) << endl;
        cout << "ѧ�ţ�" << scores[i].getId() << "������"
             << student_link.getNameById(scores[i].getId()) << endl;
        cout << "����ɼ���";
        float score;
        cin >> score;
        //scores[studentNums[i]].setValue(score);
        scores[i].setValue(score);
    }
}

void TeacherMenu::editScore() {
    cout << "����ѧ�ţ�";
    string studentId;
    cin >> studentId;
    for (auto &i: studentNums) {
        if (scores[i].getId() == studentId) {
            cout << "ԭ�ɼ���" << endl;
            cout << "ѧ�ţ�" << scores[i].getId() << "������"
                 << student_link.getNameById(scores[i].getId()) << "�ɼ���" << setprecision(3) << scores[i].getValue()
                 << endl;
            cout << "�����µĳɼ�";
            float s;
            cin >> s;
            scores[i].setValue(s);
            cout << "�޸ĳɹ�" << endl;
            return;
        }
        cout << "δ�ҵ���ѧ��" << endl;
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
    cout << "��������" << studentNums.size() << endl;
    cout << "ƽ���֣�" << setprecision(3) << total << endl;

}

void TeacherMenu::changePassword() {
    cout << "�������룺";

}

void TeacherMenu::sortByScore() {
    score_link.sortByValue();
    Display::Result();
    cout << "������" << endl;

}

void TeacherMenu::sortById() {
    score_link.sortByStudentId();
    Display::Result();
    cout << "������" << endl;

}
