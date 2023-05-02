//
// Created by Admin on 2023/5/2.
//

#include "AdminSystem.h"

void AdminSystem::adminSystem() {
    system("cls");
    cout << "1) 查看学生信息" << endl;
    cout << "2) 新增学生信息" << endl;
    cout << "3) 修改学生信息" << endl;
    cout << "4) 删除学生信息" << endl;
    cout << "5) 查看老师信息" << endl;
    cout << "6) 新增老师信息" << endl;
    cout << "7) 修改老师信息" << endl;
    cout << "8) 删除老师信息" << endl;
    cout << "9) 查看课程" << endl;
    cout << "10) 增加课程" << endl;
    cout << "11) 修改课程" << endl;
    cout << "12) 删除课程" << endl;
    cout << "13) 查看学生成绩" << endl;
    cout << "14) 录入学生成绩" << endl;
    cout << "15) 修改学生成绩" << endl;
    cout << "16) 删除学生成绩" << endl;
    cout << "17) 统计信息" << endl;
    cout << "其他) 退出" << endl;
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
        cout << "无课程" << endl;
        return;
    }
    cout << left << setw(8) << "课程id" << setw(15) << "课程名称" << setw(10) << "课程老师" << setw(10) << "课程简介"
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

