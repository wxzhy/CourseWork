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

// 查看课程信息函数
    void adminQueryCourseInfo()
    {
        system("cls");
        cout << "1) 查看所有课程信息" << endl;
        cout << "2) 详细查看某课程信息" << endl;
        cout << "其他) 返回上级" << endl;
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
            cout << "输入课程ID                  " << endl;;
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

// 界面根据课程id查询课程信息
    void displayCourseInfoByCourseId(string courseId, vector<Course> courseInfoArray, vector<Teacher> teacherInfoArray)
    {
        int found = 0;

        for (int i = 0; i < courseInfoArray.size(); i++) {
            if (courseInfoArray[i].getId() == courseId) {
                string teacherName;
//                findTeacherIndexByTeacherId();
                int index = findTeacherIndexByTeacherId(teacherInfoArray, courseInfoArray[i].getTeacherId());
                if (index == -1) {
                    cout << left << setw(8) << "课程id" << setw(15) << "课程名称" << setw(10) << "课程老师" << setw(10) << "课程简介" << endl;
                    cout << left << setw(8) << courseInfoArray[i].getId() << setw(15) << "暂无老师" << setw(10) << teacherName << setw(10) << courseInfoArray[i].getDesc() << endl;
                } else {
                    cout << left << setw(8) << "课程id" << setw(15) << "课程名称" << setw(10) << "课程老师" << setw(10) << "课程简介" << endl;
                    cout << left << setw(8) << courseInfoArray[i].getId() << setw(15) << courseInfoArray[i].getName() << setw(10) << teacherInfoArray[index].getName() << setw(10) << courseInfoArray[i].getDesc() << endl;
                }
                found = 1;
            }
        }

        if (!found) {
            cout << "未找到课程相关信息" << endl;
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
