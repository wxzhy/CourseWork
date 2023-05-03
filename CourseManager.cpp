//
// Created by Admin on 2023/5/3.
//

#include <iomanip>
#include "CourseManager.h"

void CourseManager::menu() {
    cout << "�γ̹���" << endl;
    cout << "1.�鿴ȫ���γ�" << endl;
    cout << "2.��ӿγ�" << endl;
    cout << "3.ɾ���γ�" << endl;
    cout << "4.�޸Ŀγ�" << endl;
    cout << "�����룺";

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
    cout << "����γ̱�ţ�";
    cin >> str;
    if (course_link.ifExist(str)) {
        cout << "�ñ���Ѵ��ڣ�" << endl;
        return;
    }
    Course c;
    c.setId(str);
    cout << "����γ����ƣ�";
    cin >> str;
    c.setName(str);
    cout << "����γ̽�ʦ���ţ�";
    cin >> str;
    c.setTeacherId(str);
    cout << "�����������";
    int i;
    cin >> i;
    c.setMax(i);
}


void CourseManager::showCourse() {
    print(courses);

}

void CourseManager::print(Course c) {
    cout << "�γ̱�ţ�" << c.getId() << endl;
    cout << "�γ����ƣ�" << c.getName() << endl;
    cout << "��ʦ������" << teacher_link.getNameById(c.getTeacherId()) << endl;
    cout << "��ǰ������" << c.getCurrent() << endl;
    cout << "���������" << c.getMax() << endl;
}

void CourseManager::print(vector<Course> c) {
    if (c.empty()) {
        cout << "δ�ҵ�" << endl;
        return;
    }

    cout << "+------------+---------------+-----------------+-------+-------+" << endl;
    cout << "| " << setw(10) << "�γ̱��" << " | " << setw(15) << "�γ�����" << " | "
         << setw(15) << "�ڿν�ʦ" << " | " << setw(5) << "��ǰ����" << " | "
         << setw(5) << "�������" << " |" << endl;
    cout << "+------------+---------------+-----------------+-------+-------+" << endl;

    for (auto &i: c) {
        cout << "| " << left << setw(10) << i.getId() << " | " << left << setw(15) << i.getName() << " | " << left
             << setw(15)
             << teacher_link.getNameById(i.getTeacherId()) << " | " << left << setw(5) << i.getCurrent() << " | "
             << left << setw(5) << i.getMax() << " |" << endl;
    }

    cout << "+------------+---------------+-----------------+-------+-------+" << endl;
    cout << "����" << c.size() << "�����" << endl;
}

void CourseManager::deleteCourse() {

}

void CourseManager::editCourse() {

}



