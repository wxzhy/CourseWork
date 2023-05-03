//
// Created by Admin on 2023/5/3.
//

#include "TeacherManager.h"
void TeacherManager::menu() {
    while(true) {
        cout << "1.�鿴ȫ����ʦ" << endl;
        cout << "2.���ӽ�ʦ" << endl;
        cout << "3.�޸Ľ�ʦ" << endl;
        cout << "4.ɾ����ʦ" << endl;
        cout << "5.�����Ų�ѯ" << endl;
        cout << "6.��������ѯ" << endl;
        cout << "0.����" << endl;
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
            case 0:
                return;
            default:
                cout<<"�������"<<endl;

        }
    }
}

void TeacherManager::displayAll() {
    println(teachers);

}

void TeacherManager::println(vector<Teacher> &s) {
    if(s.empty()){
        cout<<"δ�ҵ�"<<endl;
        return;
    }
    int n = 0;
    cout << setw(10) << "����" << setw(10) << "����" << setw(10) << "����" << setw(20) << "�绰" << endl;
    Line();
    for (auto &i: s) {
        cout << setw(10) << i.getId() << setw(10) << i.getName() << setw(10) << i.getDepart() << setw(20) << i.getPhone()
             << endl;
        n++;
        if (n % 20 == 0)
            system("pause");
    }
    boldLine();
    cout << "����" << n << "�����" << endl;

}

void TeacherManager::add() {
    Teacher stu;
    string str;
    cout << "���빤�ţ�";
    cin >> str;
    if (teacher_link.ifExist(str)) {
        cout << "�ù����Ѵ���" << endl;
        return;
    }
    stu.setId(str);
    cout << "����������";
    cin >> str;
    stu.setName(str);
    cout << "�����Ա�";
    cin >> str;
    stu.setSex(str);
    cout << "���벿�ţ�";
    cin >> str;
    stu.setDepart(str);
    cout << "����绰��";
    cin >> str;
    stu.setPhone(str);
    teachers.push_back(stu);
    teacher_link.sortById();

}

void TeacherManager::edit() {
    findByName();
    cout<<"����Ҫ�޸ĵĹ��ţ�";
    string id;
    cin>>id;
    int num=teacher_link.getNumById(id);
    if(num==-1) {
        cout << "δ�ҵ�" << endl;
        return;
    }
    cout<<"ԭ��Ϣ��";
    print(teachers[num]);
    cout << "1.�޸�����" << endl;
    cout << "2.�޸��Ա�" << endl;
    cout << "3.�޸�רҵ" << endl;
    cout << "4.�޸��꼶" << endl;
    int op;
    cout<<"�����룺";
    cin>>op;

    switch (op) {
        case 1:{cout<<"����������";
            string  str;
            cin>>str;
            teachers[num].setName(str);
            break;
        }
        case 2:{cout<<"�����Ա�";
            string  str;
            cin>>str;
            teachers[num].setSex(str);
            break;
        }
        case 3:{cout<<"���벿�ţ�";
            string str;
            cin>>str;
            teachers[num].setName(str);
            break;
        }
        case 4:{cout<<"����绰��";
            string str;
            cin>>str;
            teachers[num].setPhone(str);
            break;
        }
        default:cout<<"�������"<<endl;
    }

}

void TeacherManager::del() {
    cout<<"����Ҫɾ���Ĺ��ţ�";
    string id;
    cin>>id;
    int num=teacher_link.getNumById(id);
    if(num==-1) {
        cout << "δ�ҵ�" << endl;
        return;
    }
    cout<<"ԭ��Ϣ��";
    print(teachers[num]);
    cout<<"ȷ��ɾ����Yes/No����";
    string  str;
    cin>>str;
    if(str=="Yes")
        teacher_link.del(teachers[num].getId());
    cout<<"ɾ���ɹ�";
}

void TeacherManager::findById() {
    cout << "���빤�ţ�";
    string id;
    cin >> id;
    for (auto &s: teachers) {
        if (s.getId() == id) {
            print(s);
            break;
        }

    }

}

void TeacherManager::print(Teacher s) {
    cout<<"��ʦ��Ϣ��"<<endl;
    cout<<left<<setw(10)<<"���ţ�"<<s.getId()<<endl;
    cout<<left<<setw(10)<<"������"<<s.getName()<<endl;
    cout<<left<<setw(10)<<"�Ա�"<<s.getSex()<<endl;
    cout<<left<<setw(10)<<"רҵ��"<<s.getDepart()<<endl;
    cout<<left<<setw(10)<<"�꼶��"<<s.getPhone()<<endl;
    Line();


}

void TeacherManager::findByName() {
    cout<<"����������";
    string name;
    cin>>name;
    vector<Teacher> stu;
    for(auto &s:teachers){
        if(s.getName().find(name)!=-1)
            stu.push_back(s);
    }
    println(stu);
}

void TeacherManager::print(string id) {
    for(auto &s:teachers){
        if(s.getId()==id) {
            print(s);
            return;
        }
    }
    print("δ�ҵ�");

}