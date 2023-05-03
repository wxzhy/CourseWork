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
    cout << "�γ����ƣ� " << courses[courseNum].getName() << endl;
    studentNums = score_link.getScoreNumByCourseId(courses[courseNum].getId());
    cout << "1.�鿴ѧ���ɼ�" << endl;
    cout << "2.¼��ѧ���ɼ�" << endl;
    cout << "3.�޸�ѧ���ɼ�" << endl;
    cout << "4.ͳ����Ϣ" << endl;
    cout << "0.�˳�" << endl;
    int op;
    cin>>op;
    switch (op) {
        case 1:
            showScore();
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
    }
}

void TeacherMenu::getCourses() {
    courseNums = course_link.getNumByTeacherId(id);

}

void TeacherMenu::AddScore() {


}

void TeacherMenu::menu() {
    cout << "������ " << teacher_link.getNameById(id);
    getCourses();
    if (courseNums.empty()) {
        cout << "�޿γ̣�" << endl;
    } else {
        int n = 0;
        cout << "�γ���Ϣ��" << endl;
        cout << left << setw(5) << "���" << left << setw(10) << "�γ̱��" << left << setw(15) << "�γ�����" << setw(5)
             << "����" << setw(5) << "���"
             << endl;

        for (auto &s: courseNums) {
            cout << left << setw(5) << (++n) << left << setw(10) << courses[s].getId() << left << setw(15)
                 << courses[s].getName() << setw(5)
                 << courses[s].getCurrent() << setw(5) << courses[s].getMax()
                 << endl;
        }
        cout << "��ѡ��Ҫ�����Ŀγ���ţ�";
        int choice;
        cin >> choice;
        if (choice <= 0 || choice > courseNums.size()) {
            cout << "�������" << endl;
        } else {
            courseMenu(courseNums[choice - 1]);
        }
    }

}

void TeacherMenu::showCourse() {

}

void TeacherMenu::showScore() {
    if (studentNums.empty()) {
        cout << "δ�ҵ�" << endl;
        return;
    }
    int n = 0;
    cout << left << setw(10) << "ѧ��" << left << setw(10) << "����" << left << setw(5) << "�ɼ�" << endl;
    Line();
    for (auto &i: studentNums) {
        cout << left << setw(10) << scores[studentNums[i]].getId() << left << setw(10)
             << student_link.getNameById(scores[studentNums[i]].getId()) << left << setprecision(1) << setw(5)
             << scores[studentNums[i]].getValue() << endl;
        n++;
        if (n % 20 == 0)
            system("pause");
    }
        boldLine();
        cout << "����" << n << "�����" << endl;

    }



void TeacherMenu::addScore() {
    for (auto &i: studentNums) {
        cout << "ѧ�ţ�" << scores[studentNums[i]].getId()<<"������"<<student_link.getNameById(scores[studentNums[i]].getId())<<endl;
        cout<<"����ɼ���";
        float score;
        cin>>score;
        scores[studentNums[i]].setValue(score);
    }
}

void TeacherMenu::editScore() {

}

void TeacherMenu::calculate() {
    float total=0.0;

    for(auto &i: studentNums) {
        total+=scores[studentNums[i]].getValue();
    }
    total/=studentNums.size();
    cout<<"ƽ���֣�"<<setprecision(1)<<total<<endl;

}
