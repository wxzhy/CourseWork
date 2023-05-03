//
// Created by Admin on 2023/5/2.
//

#include "AdminSystem.h"
void AdminSystem::adminSystem() {

    //system("cls");
    cout << "1) �鿴ѧ����Ϣ  ";
    cout << "2) ����ѧ����Ϣ  ";
    cout << "3) �޸�ѧ����Ϣ  ";
    cout << "4) ɾ��ѧ����Ϣ  " << endl;
    cout << "5) �鿴��ʦ��Ϣ  ";
    cout << "6) ������ʦ��Ϣ  ";
    cout << "7) �޸���ʦ��Ϣ  ";
    cout << "8) ɾ����ʦ��Ϣ  " << endl;
    cout << "9) �鿴�γ�     ";
    cout << "10) ���ӿγ�    ";
    cout << "11) �޸Ŀγ�    ";
    cout << "12) ɾ���γ�    " << endl;
    cout << "13) �鿴ѧ���ɼ� ";
    cout << "14) ¼��ѧ���ɼ� ";
    cout << "15) �޸�ѧ���ɼ� ";
    cout << "16) ɾ��ѧ���ɼ� " << endl;
    cout << "17) ͳ����Ϣ" << endl;
    cout << "����) �˳�" << endl;
    cout << "> ";
    int op;
    cin >> op;

    if (op == 1)
        adminQueryStudentInfo();
    else if (op == 2)
        adminAddStudentInfo();
    else if (op == 3)
        adminModifyStudentInfo();
    else if (op == 4)
        adminDeleteStudentInfo();
    else if (op == 5)
        adminQueryTeacherInfo();
    else if (op == 6)
        adminAddTeacherInfo();
    else if (op == 7)
        adminModifyTeacherInfo();
    else if (op == 8)
        adminDeleteTeacherInfo();
    else if (op == 9)
        adminQueryCourseInfo();
    else if (op == 10)
        adminAddCourseInfo();
    else if (op == 11)
        adminModifyCourseInfo();
    else if (op == 12)
        adminDeleteCourseInfo();
    else if (op == 13)
        adminQueryStudentScoreInfo();
    else if (op == 14)
        adminAddStudentScoreInfo();
    else if (op == 15)
        adminModifyStudentScoreInfo();
    else if (op == 16)
        adminDeleteStudentScoreInfo();
    else
        exitSystem();
}

void AdminSystem::displayAllCourseInfo(vector<Course> Courses, vector<Teacher> Teachers) {
    if (courses.empty()) {
        cout << "�޿γ�" << endl;
        return;
    }
    cout << left << setw(8) << "�γ�id" << setw(15) << "�γ�����" << setw(10) << "�γ���ʦ" << setw(10) << "�γ̼��"
         << endl;
    for (auto s: Courses) {
        string teacherName = findTeacherNameById(s.getId());
        cout << left << setw(8) << s.getId() << setw(15) << s.getName() << setw(10) << teacherName << setw(10)
             << s.getCurrent() << endl;
    }
    system("pause");

}

string AdminSystem::findTeacherNameById(string teacherId) {
    for (auto t: teachers) {
        if (t.getId() == teacherId)
            return t.getName();
    }
    return "";
}

int AdminSystem::findTeacherIndexByTeacherId(vector<Teacher> teachers_link, string teacherId) {
    for (auto it = teachers.begin(); it != teachers.end(); ++it) {
        if (it->getId() == teacherId)
            return it - teachers.begin();
    }
    return 0;
}

void AdminSystem::adminQueryStudentInfo() {
    cout << "����������";
    string str;
    cin >> str;
    vector<Student> s = student_link.findByName(str);
    if (s.empty())
        cout << "δ�ҵ�" << endl;
    else {
        for (auto &stu: s) {
            if(stu.getName().find(str)!=-1)
                cout<<"ѧ��"<<stu.getId()<<"������"<<stu.getName() << endl;
        }
    }


}

void AdminSystem::adminAddStudentInfo() {
    string name, id;
    cout << "����ѧ�ţ�";
    cin >> id;
    if (student_link.ifExist(id)) {
        cout << "��ѧ���Ѵ���" << endl;
        return;
    }
    cout << "����������";
    cin >> name;
    student_link.add(id,name,"","",0);

}

void AdminSystem::adminModifyStudentInfo() {

}

void AdminSystem::adminModifyCourseInfo() {
    // ����չʾ�޸Ŀγ���Ϣ
    string courceId;

    cout << "����γ�id " << endl;
    cin >> courceId;

    int index = findCourseIndexByCourseId(courses, courceId);
    if (index == -1) {
        cout << "δ�ҵ��ÿγ�" << endl;
     //   back();
        adminSystem();
    } else {
        int op;
        while (1) {
            cout << "����Ҫ�޸ĵ���Ϣ���" << endl;
            cout << "1) �γ�����  2)�γ���ʦ  3)�γ̼��  ����)�˳�" << endl;
            cout << "> ";
            cin >> op;
            if (op == 1) {
                string courseName;
                cout << "> ";
                cin >> courseName;
                courses[index].setName(courseName);
            } else if (op == 2) {
                string teacherId;
                cout << "����γ���ʦid" << endl;
                cout << "> ";
                cin >> teacherId;
                courses[index].setTeacherId(teacherId);
            } else if (op == 3) {
                int desc;
                cout << "����γ̼��" << endl;
                cout << "> ";
                cin >> desc;
                courses[index].getCurrent();
            } else
                break;
        }
    }

    cout << "�޸ĳɹ�" << endl;
//    back();
    adminSystem();


}

int AdminSystem::findCourseIndexByCourseId(vector<Course> course, string courseId) {
    for(auto it=course.begin(); it!=course.end(); it++)
        if(it->getId()==courseId)
            return it-course.begin();
    return -1;
}

void AdminSystem::adminDeleteStudentInfo() {
    string id;
    cout<<"����ѧ�ţ�";
    cin>>id;
    if(student_link.ifExist(id)){
        student_link.del(id);
        cout<<"ɾ���ɹ���"<<endl;
    }
    else{
        cout<<"δ�ҵ���"<<endl;
    }

}

void AdminSystem::adminQueryTeacherInfo() {
    cout<<"1.����Ų���"<<endl;
    cout<<"2.����������"<<endl;
    cout<<"����������"<<endl;
    cout<<"�����룺";
    int op;
    cin>>op;
    if(op==1) { cout << "�������ţ�" << endl;
        string id;

    cin>>id;

    }

}

void AdminSystem::adminAddTeacherInfo() {
    string id,name;
    cout<<"�����ţ�";
    cin>>id;
    if(teacher_link.ifExist(id)){
        cout<<"����Ѵ��ڣ�"<<endl;
        return;
    }
    cout<<"����������";
    cin>>name;
    teacher_link.add(id,name,"","","");

}

void AdminSystem::adminDeleteTeacherInfo() {
    cout<<"�����ʦ��ţ�"<<endl;
    string id;
    cin>>id;
    if(teacher_link.ifExist(id)){
        teacher_link.del(id);
        cout<<"ɾ���ɹ���"<<endl;
    }
    else{
        cout<<"δ�ҵ���"<<endl;
    }

}

void AdminSystem::adminDeleteCourseInfo() {
    cout<<"�����ʦ��ţ�"<<endl;
    string id;
    cin>>id;
    if(course_link.ifExist(id)){
        course_link.del(id);
        cout<<"ɾ���ɹ���"<<endl;
    }
    else{
        cout<<"δ�ҵ���"<<endl;
    }

}

void AdminSystem::adminModifyTeacherInfo() {

}

void AdminSystem::adminQueryStudentScoreInfo() {
    cout<<"����ѧ�ţ�";
    string id;
    cin>>id;
    vector<Score> s=score_link.getScoreByStudentId(id);
    if(s.empty()) {
        cout<<"������"<<endl;
    }
    else{
        string studentName,courseName;
        for(auto i:s){
            studentName=student_link.getNameById(i.getStudentId());
            courseName=student_link.getNameById(i.getCourseId());
            cout<<"ѧ��������"<<studentName<<"�γ̣�"<<courseName<<"�ɼ���"<<i.getValue()<<endl;
        }
    }

}

void AdminSystem::adminAddStudentScoreInfo() {
    string sid,cid;
    float score;
    cout<<"����ѧ�ţ�";
    cin>>sid;
    cout<<"����γ̱�ţ�";
    cin>>cid;
    cout<<"����ɼ���";
    cin>>score;
    score_link.add(sid,cid,score);
}

void AdminSystem::adminModifyStudentScoreInfo() {

}

void AdminSystem::adminDeleteStudentScoreInfo() {
    string sid,cid;
    cout<<"����ѧ�ţ�";
    cin>>sid;
    cout<<"����γ̱�ţ�";
    cin>>cid;

}

void AdminSystem::exitSystem() {
    exit(0);
}

void AdminSystem::adminAddCourseInfo() {

}

