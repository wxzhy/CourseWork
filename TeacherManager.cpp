//
// Created by Admin on 2023/5/3.
//

#include "TeacherManager.h"

void TeacherManager::menu() {
    while (true) {
        Display::Head(">>����ģ��>>��ʦ����");
        cout << "     1.�鿴ȫ����ʦ" << endl;
        cout << "     2.��ӽ�ʦ" << endl;
        cout << "     3.�޸Ľ�ʦ" << endl;
        cout << "     4.ɾ����ʦ" << endl;
        cout << "     5.�����Ų�ѯ" << endl;
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
                loadFromFile();
                break;
            case 0:
                return;
            default:
                cout << "�������" << endl;

        }
    }
}

void TeacherManager::displayAll() {
    print(teachers);

}

void TeacherManager::print(vector<Teacher> &s) {
    if (s.empty()) {
        cout << "δ�ҵ�" << endl;
        return;
    }
    int n = 0;
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    cout << "|     ����     |     ����     |     ����     |          �绰          |" << endl;
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    for (auto &i: s) {
        cout << "| " << setw(12) << i.getId() << " | " << setw(12) << i.getName() << " | " << setw(12) << i.getDepart()
             << " | " << setw(22) << i.getPhone() << " |" << endl;
        n++;
        if (n % 20 == 0)
            system("pause>nul");
    }
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    cout << "����" << n << "�����" << endl;
    system("pause>nul");
}


void TeacherManager::add() {
    Teacher teacher;
    string str;
    cout << "���빤�ţ�";
    cin >> str;
    if (teacher_link.ifExist(str)) {
        cout << "�ù����Ѵ���" << endl;
        return;
    }
    teacher.setId(str);
    teacher.setPassword(str);
    cout << "����������";
    cin >> str;
    teacher.setName(str);
    cout << "�����Ա�";
    cin >> str;
    teacher.setSex(str);
    cout << "���벿�ţ�";
    cin >> str;
    teacher.setDepart(str);
    cout << "����绰��";
    cin >> str;
    teacher.setPhone(str);
    teachers.push_back(teacher);
    teacher_link.sortById();

}

void TeacherManager::edit() {
    //findByName();
    cout << "����Ҫ�޸ĵĹ��ţ�";
    string id;
    cin >> id;
    int num = teacher_link.getNumById(id);
    if (num == -1) {
        Display::Result();
        cout << "δ�ҵ�" << endl;
        return;
    }
    //cout << "ԭ��Ϣ��";
    Display::Message("ԭ��Ϣ");
    print(teachers[num]);
    Display::Head(">>����ģ��>>��ʦ����>>�޸Ľ�ʦ");
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
            teachers[num].setName(str);
            break;
        }
        case 2: {
            cout << "�����Ա�";
            string str;
            cin >> str;
            teachers[num].setSex(str);
            break;
        }
        case 3: {
            cout << "���벿�ţ�";
            string str;
            cin >> str;
            teachers[num].setName(str);
            break;
        }
        case 4: {
            cout << "����绰��";
            string str;
            cin >> str;
            teachers[num].setPhone(str);
            break;
        }
        default:
            cout << "�������" << endl;
    }

}

void TeacherManager::del() {
    cout << "����Ҫɾ���Ĺ��ţ�";
    string id;
    cin >> id;
    int num = teacher_link.getNumById(id);
    if (num == -1) {
        cout << "δ�ҵ�" << endl;
        return;
    }
    cout << "ԭ��Ϣ��";
    print(teachers[num]);
    cout << "ȷ��ɾ����Yes/No����";
    string str;
    cin >> str;
    if (str == "Yes") {
        teacher_link.del(teachers[num].getId());
        cout << "ɾ���ɹ�" << endl;
    }
}

void TeacherManager::findById() {
    cout << "���빤�ţ�";
    string id;
    cin >> id;
    for (auto &s: teachers) {
        if (s.getId() == id) {
            Display::Message();
            print(s);
            break;
        }

    }

}

void TeacherManager::print(Teacher s) {
    //cout << "��ʦ��Ϣ��" << endl;
    //cout << left << setw(10) << "���ţ�" << s.getId() << endl;
    //cout << left << setw(10) << "������" << s.getName() << endl;
    //cout << left << setw(10) << "�Ա�" << s.getSex() << endl;
    //cout << left << setw(10) << "רҵ��" << s.getDepart() << endl;
    //cout << left << setw(10) << "�꼶��" << s.getPhone() << endl;
    //Line();
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    cout << "|     ����     |     ����     |     ����     |          �绰          |" << endl;
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    {
        cout << "| " << setw(12) << s.getId() << " | " << setw(12) << s.getName() << " | " << setw(12) << s.getDepart()
             << " | " << setw(22) << s.getPhone() << " |" << endl;
    }
    cout << "+--------------+--------------+--------------+------------------------+" << endl;
    cout << "����" << 1 << "�����" << endl;
    system("pause>nul");

}

void TeacherManager::findByName() {
    cout << "����������";
    string name;
    cin >> name;
    vector<Teacher> stu;
    for (auto &s: teachers) {
        if (s.getName().find(name) != -1)
            stu.push_back(s);
    }
    Display::Message();
    print(stu);
}

void TeacherManager::print(string id) {
    for (auto &s: teachers) {
        if (s.getId() == id) {
            print(s);
            return;
        }
    }
    Display::Result();
    print("δ�ҵ�");

}

void TeacherManager::loadFromFile() {
    cout << "�����ļ�����";
    string filename;
    cin >> filename;
    teacher_link.load(filename);

}
