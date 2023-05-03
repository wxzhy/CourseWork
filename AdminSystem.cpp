//
// Created by Admin on 2023/5/2.
//

#include "AdminSystem.h"
void AdminSystem::adminSystem() {

    //system("cls");
    cout << "1) 查看学生信息  ";
    cout << "2) 新增学生信息  ";
    cout << "3) 修改学生信息  ";
    cout << "4) 删除学生信息  " << endl;
    cout << "5) 查看老师信息  ";
    cout << "6) 新增老师信息  ";
    cout << "7) 修改老师信息  ";
    cout << "8) 删除老师信息  " << endl;
    cout << "9) 查看课程     ";
    cout << "10) 增加课程    ";
    cout << "11) 修改课程    ";
    cout << "12) 删除课程    " << endl;
    cout << "13) 查看学生成绩 ";
    cout << "14) 录入学生成绩 ";
    cout << "15) 修改学生成绩 ";
    cout << "16) 删除学生成绩 " << endl;
    cout << "17) 统计信息" << endl;
    cout << "其他) 退出" << endl;
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
        cout << "无课程" << endl;
        return;
    }
    cout << left << setw(8) << "课程id" << setw(15) << "课程名称" << setw(10) << "课程老师" << setw(10) << "课程简介"
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
    cout << "输入姓名：";
    string str;
    cin >> str;
    vector<Student> s = student_link.findByName(str);
    if (s.empty())
        cout << "未找到" << endl;
    else {
        for (auto &stu: s) {
            if(stu.getName().find(str)!=-1)
                cout<<"学号"<<stu.getId()<<"姓名："<<stu.getName() << endl;
        }
    }


}

void AdminSystem::adminAddStudentInfo() {
    string name, id;
    cout << "输入学号：";
    cin >> id;
    if (student_link.ifExist(id)) {
        cout << "该学号已存在" << endl;
        return;
    }
    cout << "输入姓名：";
    cin >> name;
    student_link.add(id,name,"","",0);

}

void AdminSystem::adminModifyStudentInfo() {

}

void AdminSystem::adminModifyCourseInfo() {
    // 界面展示修改课程信息
    string courceId;

    cout << "输入课程id " << endl;
    cin >> courceId;

    int index = findCourseIndexByCourseId(courses, courceId);
    if (index == -1) {
        cout << "未找到该课程" << endl;
     //   back();
        adminSystem();
    } else {
        int op;
        while (1) {
            cout << "输入要修改的信息序号" << endl;
            cout << "1) 课程名称  2)课程老师  3)课程简介  其他)退出" << endl;
            cout << "> ";
            cin >> op;
            if (op == 1) {
                string courseName;
                cout << "> ";
                cin >> courseName;
                courses[index].setName(courseName);
            } else if (op == 2) {
                string teacherId;
                cout << "输入课程老师id" << endl;
                cout << "> ";
                cin >> teacherId;
                courses[index].setTeacherId(teacherId);
            } else if (op == 3) {
                int desc;
                cout << "输入课程简介" << endl;
                cout << "> ";
                cin >> desc;
                courses[index].getCurrent();
            } else
                break;
        }
    }

    cout << "修改成功" << endl;
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
    cout<<"输入学号：";
    cin>>id;
    if(student_link.ifExist(id)){
        student_link.del(id);
        cout<<"删除成功！"<<endl;
    }
    else{
        cout<<"未找到！"<<endl;
    }

}

void AdminSystem::adminQueryTeacherInfo() {
    cout<<"1.按编号查找"<<endl;
    cout<<"2.按姓名查找"<<endl;
    cout<<"其他）返回"<<endl;
    cout<<"请输入：";
    int op;
    cin>>op;
    if(op==1) { cout << "请输入编号：" << endl;
        string id;

    cin>>id;

    }

}

void AdminSystem::adminAddTeacherInfo() {
    string id,name;
    cout<<"输入编号：";
    cin>>id;
    if(teacher_link.ifExist(id)){
        cout<<"编号已存在！"<<endl;
        return;
    }
    cout<<"输入姓名：";
    cin>>name;
    teacher_link.add(id,name,"","","");

}

void AdminSystem::adminDeleteTeacherInfo() {
    cout<<"输入教师编号："<<endl;
    string id;
    cin>>id;
    if(teacher_link.ifExist(id)){
        teacher_link.del(id);
        cout<<"删除成功！"<<endl;
    }
    else{
        cout<<"未找到！"<<endl;
    }

}

void AdminSystem::adminDeleteCourseInfo() {
    cout<<"输入教师编号："<<endl;
    string id;
    cin>>id;
    if(course_link.ifExist(id)){
        course_link.del(id);
        cout<<"删除成功！"<<endl;
    }
    else{
        cout<<"未找到！"<<endl;
    }

}

void AdminSystem::adminModifyTeacherInfo() {

}

void AdminSystem::adminQueryStudentScoreInfo() {
    cout<<"输入学号：";
    string id;
    cin>>id;
    vector<Score> s=score_link.getScoreByStudentId(id);
    if(s.empty()) {
        cout<<"不存在"<<endl;
    }
    else{
        string studentName,courseName;
        for(auto i:s){
            studentName=student_link.getNameById(i.getStudentId());
            courseName=student_link.getNameById(i.getCourseId());
            cout<<"学生姓名："<<studentName<<"课程："<<courseName<<"成绩："<<i.getValue()<<endl;
        }
    }

}

void AdminSystem::adminAddStudentScoreInfo() {
    string sid,cid;
    float score;
    cout<<"输入学号：";
    cin>>sid;
    cout<<"输入课程编号：";
    cin>>cid;
    cout<<"输入成绩：";
    cin>>score;
    score_link.add(sid,cid,score);
}

void AdminSystem::adminModifyStudentScoreInfo() {

}

void AdminSystem::adminDeleteStudentScoreInfo() {
    string sid,cid;
    cout<<"输入学号：";
    cin>>sid;
    cout<<"输入课程编号：";
    cin>>cid;

}

void AdminSystem::exitSystem() {
    exit(0);
}

void AdminSystem::adminAddCourseInfo() {

}

