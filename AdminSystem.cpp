//
// Created by Admin on 2023/5/2.
//

#include "AdminSystem.h"

void AdminSystem::adminSystem() {
    system("cls");
    cout << "1) �鿴ѧ����Ϣ" << endl;
    cout << "2) ����ѧ����Ϣ" << endl;
    cout << "3) �޸�ѧ����Ϣ" << endl;
    cout << "4) ɾ��ѧ����Ϣ" << endl;
    cout << "5) �鿴��ʦ��Ϣ" << endl;
    cout << "6) ������ʦ��Ϣ" << endl;
    cout << "7) �޸���ʦ��Ϣ" << endl;
    cout << "8) ɾ����ʦ��Ϣ" << endl;
    cout << "9) �鿴�γ�" << endl;
    cout << "10) ���ӿγ�" << endl;
    cout << "11) �޸Ŀγ�" << endl;
    cout << "12) ɾ���γ�" << endl;
    cout << "13) �鿴ѧ���ɼ�" << endl;
    cout << "14) ¼��ѧ���ɼ�" << endl;
    cout << "15) �޸�ѧ���ɼ�" << endl;
    cout << "16) ɾ��ѧ���ɼ�" << endl;
    cout << "17) ͳ����Ϣ" << endl;
    cout << "����) �˳�" << endl;
    cout << "> ";
    int op;
    cin >> op;

/*    if (op == 1)
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
    exitSystem();*/
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
             << s.getDesc() << endl;
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

