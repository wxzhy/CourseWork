//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_ADMINSYSTEM_H
#define COURSEWORK_ADMINSYSTEM_H
#include <iostream>
#include<iomanip>
#include <vector>
#include "Course.h"
#include "Teacher.h"
#include"Database.h"
using namespace std;
class AdminSystem :public Database{
public:
    void adminSystem();

    void displayAllCourseInfo(vector<Course> Courses, vector<Teacher> Teachers);

// �鿴�γ���Ϣ����
    void adminQueryCourseInfo()
    {
        system("cls");
        cout << "1) �鿴���пγ���Ϣ" << endl;
        cout << "2) ��ϸ�鿴ĳ�γ���Ϣ" << endl;
        cout << "����) �����ϼ�" << endl;
        cout << "> ";
        int op;

        cin >> op;
        if (op == 1) {
            int n;
/*            Course *courseInfoArray = courses;
            Teacher *teacherInfoArray = teachers;*/
            system("cls");

            displayAllCourseInfo(courses, teachers);
//            delete[] courseInfoArray;
//            delete[] teacherInfoArray;
            adminSystem();
        }
        else if (op == 2) {
            int n;
/*            Course *courseInfoArray = courses;
            Teacher *teacherInfoArray = teachers;*/
            system("cls");
            string courseId;
            cout << "����γ�ID                  " << endl;;
            cout << "> ";
            cin >> courseId;

            displayCourseInfoByCourseId(courseId, courses, teachers);
//            delete[] courseInfoArray;
//            delete[] teacherInfoArray;
            adminSystem();
        }
        else
            adminSystem();
    }


    int findTeacherIndexByTeacherId(vector<Teacher> teachers_link,string teacherId);

// ������ݿγ�id��ѯ�γ���Ϣ
    void displayCourseInfoByCourseId(string courseId, vector<Course> courseInfoArray, vector<Teacher> teacherInfoArray)
    {
        int found = 0;

        for (int i = 0; i < courseInfoArray.size(); i++) {
            if (courseInfoArray[i].getId() == courseId) {
                string teacherName;
//                findTeacherIndexByTeacherId();
                int index = findTeacherIndexByTeacherId(teacherInfoArray, courseInfoArray[i].getTeacherId());
                if (index == -1) {
                    cout << left << setw(8) << "�γ�id" << setw(15) << "�γ�����" << setw(10) << "�γ���ʦ" << setw(10) << "�γ̼��" << endl;
                    cout << left << setw(8) << courseInfoArray[i].getId() << setw(15) << "������ʦ" << setw(10) << teacherName << setw(10) << courseInfoArray[i].getDesc() << endl;
                } else {
                    cout << left << setw(8) << "�γ�id" << setw(15) << "�γ�����" << setw(10) << "�γ���ʦ" << setw(10) << "�γ̼��" << endl;
                    cout << left << setw(8) << courseInfoArray[i].getId() << setw(15) << courseInfoArray[i].getName() << setw(10) << teacherInfoArray[index].getName() << setw(10) << courseInfoArray[i].getDesc() << endl;
                }
                found = 1;
            }
        }

        if (!found) {
            cout << "δ�ҵ��γ������Ϣ" << endl;
        }
       // back();
    }

    string findTeacherNameById(string basicString);


    void adminAddCourseInfo();

    void adminQueryStudentInfo();

    void adminAddStudentInfo();

    void adminModifyStudentInfo();

    void adminModifyCourseInfo();

    int findCourseIndexByCourseId(vector<Course> course, string courseId);

    void adminDeleteStudentInfo();

    void adminQueryTeacherInfo();

    void adminAddTeacherInfo();

    void adminDeleteTeacherInfo();

    void adminDeleteCourseInfo();

    void adminModifyTeacherInfo();

    void adminQueryStudentScoreInfo();

    void adminAddStudentScoreInfo();

    void adminModifyStudentScoreInfo();

    void adminDeleteStudentScoreInfo();

    void exitSystem();
};


#endif //COURSEWORK_ADMINSYSTEM_H
