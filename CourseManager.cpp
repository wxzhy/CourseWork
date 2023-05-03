//
// Created by Admin on 2023/5/3.
//

#include <iomanip>
#include "CourseManager.h"

void CourseManager::menu() {
    while (true) {
        cout << "�γ̹���" << endl;
        cout << "1.�鿴ȫ���γ�" << endl;
        cout << "2.��ӿγ�" << endl;
        cout << "3.ɾ���γ�" << endl;
        cout << "4.�޸Ŀγ�" << endl;
        cout << "5.����Ų�ѯ" << endl;
        cout << "6.ģ����ѯ" << endl;
        cout << "0.�˳�" << endl;
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
            case 5:
                findById();
            case 0:
                return;
            default:
                cout << "�������" << endl;
        }
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
    cout << "�������������";
    int i;
    cin >> i;
    c.setMax(i);
    courses.push_back(c);
    course_link.sortById();
    cout << "��ӳɹ�" << endl;
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

    cout << "+------------+-----------------+-----------------+----------+----------+" << endl;
    cout << "| " << setw(10) << "�γ̱��" << " | " << setw(15) << "�γ�����" << " | "
         << setw(15) << "�ڿν�ʦ" << " | " << setw(8) << "��ǰ����" << " | "
         << setw(8) << "�������" << " |" << endl;
    cout << "+------------+-----------------+-----------------+----------+----------+" << endl;

    for (auto &i: c) {
        cout << "| " << left << setw(10) << i.getId() << " | " << left << setw(15) << i.getName() << " | " << left
             << setw(15)
             << teacher_link.getNameById(i.getTeacherId()) << " | " << right << setw(8) << i.getCurrent() << " | "
             << right << setw(8) << i.getMax() << " |" << endl;
    }

    cout << "+------------+-----------------+-----------------+----------+----------+" << endl;
    cout << "����" << c.size() << "�����" << endl;
}


void CourseManager::deleteCourse() {
    cout << "����Ҫɾ���Ŀγ̱�ţ�";
    string id;
    cin >> id;
    int num = course_link.getNumById(id);
    if (num == -1) {
        cout << "δ�ҵ�" << endl;
        return;
    }
    cout << "ԭ��Ϣ��";
    print(courses[num]);
    cout << "ȷ��ɾ����Yes/No����";
    string str;
    cin >> str;
    if (str == "Yes")
        course_link.del(teachers[num].getId());
    cout << "ɾ���ɹ�";

}

void CourseManager::editCourse() {
    search();
    cout << "����Ҫ�޸ĵı�ţ�";
    string id;
    cin >> id;
    int num = course_link.getNumById(id);
    if (num == -1) {
        cout << "δ�ҵ�" << endl;
        return;
    }
    cout << "ԭ��Ϣ��";
    print(courses[num]);
    cout << "1.�޸�����" << endl;
    cout << "2.�޸Ľ�ʦ" << endl;
    cout << "3.�޸��������" << endl;
    cout << "�����룺";
    int op;
    switch (op) {
        case 1: {
            cout << "�������ƣ�";
            string str;
            cin >> str;
            courses[num].setName(str);
            break;
        }
        case 2: {
            cout << "�����ʦ��ţ�";
            string str;
            cin >> str;
            courses[num].setTeacherId(str);
            break;
        }
        case 3: {
            cout << "���������Ա��";
            int max;
            cin >> max;
            courses[num].setMax(max);
            break;
        }
        default:
            cout << "�������" << endl;
    }
}

void CourseManager::findById() {
    cout << "����γ̱�ţ�";
    string id;
    cin >> id;
    for (auto &s: courses) {
        if (s.getId() == id) {
            print(s);
            return;
        }
    }
    cout << "δ�ҵ�" << endl;
}

void CourseManager::search() {
    cout << "�������ƣ�";
    string name;
    cin >> name;
    vector<Course> c;
    for (auto &s: courses) {
        if (s.getName().find(name) != -1 || teacher_link.getNameById(s.getTeacherId()).find(name) != -1)
            c.push_back(s);
    }
    print(c);

}



