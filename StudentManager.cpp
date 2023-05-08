//
// Created by Admin on 2023/5/2.
//

#include "StudentManager.h"
#include "Link.h"

void StudentManager::menu() {
    while (true) {
        Display::Head(">>����ģ��>>ѧ������");
        cout << "     1.�鿴ȫ��ѧ��" << endl;
        cout << "     2.���ѧ��" << endl;
        cout << "     3.�޸�ѧ��" << endl;
        cout << "     4.ɾ��ѧ��" << endl;
        cout << "     5.��ѧ�Ų�ѯ" << endl;
        cout << "     6.��������ѯ" << endl;
        cout << "     7.���ļ����" << endl;
        cout << "     0.�����ϼ��˵�" << endl;
        Display::Tail();
        cout << "�����룺";
        int op;
        cin >> op;
        switch (op) {
            case 1:
                displayAll();
                break;
            case 2:
                add();
                break;
            case 3:
                edit();
                break;
            case 4:
                del();
                break;
            case 5:
                findById();
                break;
            case 6:
                findByName();
                break;
            case 7:
                addFromFile();
                break;
            case 0:
                return;
            default:
                cout << "�������" << endl;

        }
    }
}

void StudentManager::displayAll() {
    print(students);

}

void StudentManager::print(vector<Student> &s) {
    if (s.empty()) {
        cout << "δ�ҵ�" << endl;
        return;
    }

    cout << "+------------+------------+------------+--------+" << endl;
    cout << "| " << setw(10) << "ѧ��" << " | " << setw(10) << "����" << " | "
         << setw(10) << "רҵ" << " | " << setw(6) << "�꼶" << " |" << endl;
    cout << "+------------+------------+------------+--------+" << endl;
    int n = 0;
    for (auto &i: s) {
        n++;
        cout << "| " << left << setw(10) << i.getId() << " | " << left << setw(10) << i.getName() << " | " << left
             << setw(10)
             << i.getProf() << " | " << left << setw(6) << i.getGrade() << " |" << endl;
        if (n % 20 == 0) {
            system("pause");
        }
    }

    cout << "+------------+------------+------------+--------+" << endl;
    cout << "����" << n << "�����" << endl;
}


void StudentManager::add() {
    Student stu;
    string str;
    cout << "����ѧ�ţ�";
    cin >> str;
    if (student_link.ifExist(str)) {
        cout << "��ѧ���Ѵ���" << endl;
        return;
    }
    stu.setId(str);
    cout << "����������";
    cin >> str;
    stu.setName(str);
    cout << "�����Ա�";
    cin >> str;
    stu.setSex(str);
    cout << "����רҵ��";
    cin >> str;
    stu.setProf(str);
    cout << "�����꼶��";
    int grade;
    cin >> grade;
    stu.setGrade(grade);
    students.push_back(stu);
    student_link.sortById();

}

void StudentManager::edit() {
    //findByName();
    cout << "����Ҫ�޸ĵ�ѧ�ţ�";
    string id;
    cin >> id;
    int num = student_link.getNumById(id);
    if (num == -1) {
        cout << "δ�ҵ�" << endl;
        return;
    }
    //cout << "ԭ��Ϣ��";
    Display::Message("ԭ��Ϣ");
    print(students[num]);
    Display::Head(">>����ģ��>>ѧ������>>�޸�ѧ��");
    cout << "     1.�޸�����" << endl;
    cout << "     2.�޸��Ա�" << endl;
    cout << "     3.�޸�רҵ" << endl;
    cout << "     4.�޸��꼶" << endl;
    Display::Tail();
    int op;
    cout << "�����룺";
    cin >> op;

    switch (op) {
        case 1: {
            cout << "����������";
            string str;
            cin >> str;
            students[num].setName(str);
            break;
        }
        case 2: {
            cout << "�����Ա�";
            string str;
            cin >> str;
            students[num].setSex(str);
            break;
        }
        case 3: {
            cout << "����רҵ��";
            string str;
            cin >> str;
            students[num].setName(str);
            break;
        }
        case 4: {
            cout << "�����꼶��";
            int str;
            cin >> str;
            students[num].setGrade(str);
            break;
        }
        default:
            cout << "�������" << endl;
    }

}

void StudentManager::del() {
    cout << "����Ҫɾ����ѧ�ţ�";
    string id;
    cin >> id;
    int num = student_link.getNumById(id);
    if (num == -1) {
        cout << "δ�ҵ�" << endl;
        return;
    }
    cout << "ԭ��Ϣ��";
    print(students[num]);
    cout << "ȷ��ɾ����Yes/No����";
    string str;
    cin >> str;
    if (str == "Yes") {
        student_link.del(students[num].getId());
        score_link.deleteByStudentId(students[num].getId());
        cout << "ɾ���ɹ�" << endl;
    }

}

void StudentManager::findById() {
    cout << "����ѧ�ţ�";
    string id;
    cin >> id;
    for (auto &s: students) {
        if (s.getId() == id) {
            print(s);
            break;
        }

    }

}

void StudentManager::print(Student s) {
    //cout << "ѧ����Ϣ��" << endl;
    //cout << left << setw(10) << "ѧ�ţ�" << s.getId() << endl;
    //cout << left << setw(10) << "������" << s.getName() << endl;
    //cout << left << setw(10) << "�Ա�" << s.getSex() << endl;
    //cout << left << setw(10) << "רҵ��" << s.getProf() << endl;
    //cout << left << setw(10) << "�꼶��" << s.getGrade() << endl;
    //Line();
    cout << "+------------+------------+------------+--------+" << endl;
    cout << "| " << setw(10) << "ѧ��" << " | " << setw(10) << "����" << " | "
         << setw(10) << "רҵ" << " | " << setw(6) << "�꼶" << " |" << endl;
    cout << "+------------+------------+------------+--------+" << endl;
    {

        cout << "| " << left << setw(10) << s.getId() << " | " << left << setw(10) << s.getName() << " | " << left
             << setw(10)
             << s.getProf() << " | " << left << setw(6) << s.getGrade() << " |" << endl;
    }

    cout << "+------------+------------+------------+--------+" << endl;
    cout << "����" << 1 << "�����" << endl;

}

void StudentManager::findByName() {
    cout << "����������";
    string name;
    cin >> name;
    vector<Student> stu;
    for (auto &s: students) {
        if (s.getName().find(name) != -1)
            stu.push_back(s);
    }
    print(stu);
}

void StudentManager::print(string id) {
    for (auto &s: students) {
        if (s.getId() == id) {
            print(s);
            return;
        }
    }
    print("δ�ҵ�");

}

void StudentManager::addFromFile() {
    cout << "�����ļ�����";
    string filename;
    cin >> filename;
    student_link.load(filename);

}
