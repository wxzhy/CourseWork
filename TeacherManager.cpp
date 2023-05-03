//
// Created by Admin on 2023/5/3.
//

#include "TeacherManager.h"
void TeacherManager::menu() {
    while(true) {
        cout << "1.查看全部教师" << endl;
        cout << "2.添加教师" << endl;
        cout << "3.修改教师" << endl;
        cout << "4.删除教师" << endl;
        cout << "5.按工号查询" << endl;
        cout << "6.按姓名查询" << endl;
        cout << "0.返回" << endl;
        cout << "请输入：";
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
                cout<<"输入错误！"<<endl;

        }
    }
}

void TeacherManager::displayAll() {
    println(teachers);

}

void TeacherManager::println(vector<Teacher> &s) {
    if(s.empty()){
        cout<<"未找到"<<endl;
        return;
    }
    int n = 0;
    cout << setw(10) << "工号" << setw(10) << "姓名" << setw(10) << "部门" << setw(20) << "电话" << endl;
    Line();
    for (auto &i: s) {
        cout << setw(10) << i.getId() << setw(10) << i.getName() << setw(10) << i.getDepart() << setw(20) << i.getPhone()
             << endl;
        n++;
        if (n % 20 == 0)
            system("pause");
    }
    boldLine();
    cout << "共有" << n << "条结果" << endl;

}

void TeacherManager::add() {
    Teacher stu;
    string str;
    cout << "输入工号：";
    cin >> str;
    if (teacher_link.ifExist(str)) {
        cout << "该工号已存在" << endl;
        return;
    }
    stu.setId(str);
    cout << "输入姓名：";
    cin >> str;
    stu.setName(str);
    cout << "输入性别：";
    cin >> str;
    stu.setSex(str);
    cout << "输入部门：";
    cin >> str;
    stu.setDepart(str);
    cout << "输入电话：";
    cin >> str;
    stu.setPhone(str);
    teachers.push_back(stu);
    teacher_link.sortById();

}

void TeacherManager::edit() {
    findByName();
    cout<<"输入要修改的工号：";
    string id;
    cin>>id;
    int num=teacher_link.getNumById(id);
    if(num==-1) {
        cout << "未找到" << endl;
        return;
    }
    cout<<"原信息：";
    print(teachers[num]);
    cout << "1.修改姓名" << endl;
    cout << "2.修改性别" << endl;
    cout << "3.修改专业" << endl;
    cout << "4.修改年级" << endl;
    int op;
    cout<<"请输入：";
    cin>>op;

    switch (op) {
        case 1:{cout<<"输入姓名：";
            string  str;
            cin>>str;
            teachers[num].setName(str);
            break;
        }
        case 2:{cout<<"输入性别：";
            string  str;
            cin>>str;
            teachers[num].setSex(str);
            break;
        }
        case 3:{cout<<"输入部门：";
            string str;
            cin>>str;
            teachers[num].setName(str);
            break;
        }
        case 4:{cout<<"输入电话：";
            string str;
            cin>>str;
            teachers[num].setPhone(str);
            break;
        }
        default:cout<<"输入错误！"<<endl;
    }

}

void TeacherManager::del() {
    cout<<"输入要删除的工号：";
    string id;
    cin>>id;
    int num=teacher_link.getNumById(id);
    if(num==-1) {
        cout << "未找到" << endl;
        return;
    }
    cout<<"原信息：";
    print(teachers[num]);
    cout<<"确认删除（Yes/No）：";
    string  str;
    cin>>str;
    if(str=="Yes")
        teacher_link.del(teachers[num].getId());
    cout<<"删除成功";
}

void TeacherManager::findById() {
    cout << "输入工号：";
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
    cout<<"教师信息："<<endl;
    cout<<left<<setw(10)<<"工号："<<s.getId()<<endl;
    cout<<left<<setw(10)<<"姓名："<<s.getName()<<endl;
    cout<<left<<setw(10)<<"性别："<<s.getSex()<<endl;
    cout<<left<<setw(10)<<"专业："<<s.getDepart()<<endl;
    cout<<left<<setw(10)<<"年级："<<s.getPhone()<<endl;
    Line();


}

void TeacherManager::findByName() {
    cout<<"输入姓名：";
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
    print("未找到");

}