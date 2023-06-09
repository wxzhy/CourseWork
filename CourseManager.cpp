//
// Created by Admin on 2023/5/3.
//



#include "CourseManager.h"


void CourseManager::menu() {
    while (true) {
        //cout << "课程管理" << endl;
        Display::Head(">>管理模块>>课程管理");
        cout << "     1.查看全部课程" << endl;
        cout << "     2.添加课程" << endl;
        cout << "     3.删除课程" << endl;
        cout << "     4.修改课程" << endl;
        cout << "     5.按编号查询" << endl;
        cout << "     6.模糊查询" << endl;
        cout << "     7.从文件添加" << endl;
        cout << "     0.返回上级菜单" << endl;
        Display::Tail();
        cout << "请输入：";

        int op;
        cin >> op;
        switch (op) {
            case 1:
                showCourse();
                break;
            case 2:
                addCourse();
                break;
            case 3:
                deleteCourse();
                break;
            case 4:
                editCourse();
                break;
            case 5:
                findById();
                break;
            case 6:
                search();
                break;
            case 7:
                addFromFile();
                break;
            case 0:
                return;
            default:
                cout << "输入错误！" << endl;
        }
    }
}

void CourseManager::addCourse() {
    string str;
    cout << "输入课程编号：";
    cin >> str;
    if (course_link.ifExist(str)) {
        cout << "该编号已存在！" << endl;
        return;
    }
    Course c;
    c.setId(str);
    cout << "输入课程名称：";
    cin >> str;
    c.setName(str);
    cout << "输入课程教师工号：";
    cin >> str;
    c.setTeacherId(str);
    cout << "输入最大人数：";
    int i;
    cin >> i;
    c.setMax(i);
    courses.push_back(c);
    course_link.sortById();
    cout << "添加成功" << endl;
}


void CourseManager::showCourse() {
    print(courses);

}

void CourseManager::print(Course c) {
    //cout << "课程编号：" << c.getId() << endl;
    //cout << "课程名称：" << c.getName() << endl;
    //cout << "教师姓名：" << teacher_link.getNameById(c.getTeacherId()) << endl;
    //cout << "当前人数：" << c.getCurrent() << endl;
    //cout << "最大人数：" << c.getMax() << endl;
    cout << "+------------+-----------------+-----------------+----------+----------+" << endl;
    cout << "| " << setw(10) << "课程编号" << " | " << setw(15) << "课程名称" << " | "
         << setw(15) << "授课教师" << " | " << setw(8) << "当前人数" << " | "
         << setw(8) << "最大人数" << " |" << endl;
    cout << "+------------+-----------------+-----------------+----------+----------+" << endl;

    {
        cout << "| " << left << setw(10) << c.getId() << " | " << left << setw(15) << c.getName() << " | " << left
             << setw(15)
             << teacher_link.getNameById(c.getTeacherId()) << " | " << right << setw(8) << c.getCurrent() << " | "
             << right << setw(8) << c.getMax() << " |" << endl;
    }

    cout << "+------------+-----------------+-----------------+----------+----------+" << endl;
    cout << "共有" << 1 << "条结果" << endl;
}

void CourseManager::print(vector<Course> c) {
    if (c.empty()) {
        cout << "未找到" << endl;
        return;
    }
    cout << "+------------+-----------------+-----------------+----------+----------+" << endl;
    cout << "| " << setw(10) << "课程编号" << " | " << setw(15) << "课程名称" << " | "
         << setw(15) << "授课教师" << " | " << setw(8) << "当前人数" << " | "
         << setw(8) << "最大人数" << " |" << endl;
    cout << "+------------+-----------------+-----------------+----------+----------+" << endl;
    int n = 0;
    for (auto &i: c) {
        cout << "| " << left << setw(10) << i.getId() << " | " << left << setw(15) << i.getName() << " | " << left
             << setw(15)
             << teacher_link.getNameById(i.getTeacherId()) << " | " << right << setw(8) << i.getCurrent() << " | "
             << right << setw(8) << i.getMax() << " |" << endl;
        if ((++n) % 20 == 0) {
            system("pause>nul");
        }
    }

    cout << "+------------+-----------------+-----------------+----------+----------+" << endl;
    cout << "共有" << c.size() << "条结果" << endl;
    system("pause>nul");
}


void CourseManager::deleteCourse() {
    cout << "输入要删除的课程编号；";
    string id;
    cin >> id;
    int num = course_link.getNumById(id);
    if (num == -1) {
        cout << "未找到" << endl;
        return;
    }
    cout << "原信息：";
    print(courses[num]);
    cout << "确认删除（Yes/No）：";
    string str;
    cin >> str;
    if (str == "Yes") {
        course_link.del(teachers[num].getId());
        cout << "删除成功" << endl;
    }

}

void CourseManager::editCourse() {
    //search();
    cout << "输入要修改的编号：";
    string id;
    cin >> id;
    int num = course_link.getNumById(id);
    if (num == -1) {
        cout << "未找到" << endl;
        return;
    }
    //cout << "原信息：";
    Display::Message("原信息");
    print(courses[num]);
    Display::Head(">>管理模块>>课程管理>>修改课程");
    cout << "     1.修改名称" << endl;
    cout << "     2.修改教师" << endl;
    cout << "     3.修改最大人数" << endl;
    Display::Tail();
    cout << "请输入：";
    int op;
    cin >> op;
    switch (op) {
        case 1: {
            cout << "输入名称：";
            string str;
            cin >> str;
            courses[num].setName(str);
            cout << "修改成功" << endl;
            break;
        }
        case 2: {
            cout << "输入教师编号：";
            string str;
            cin >> str;
            courses[num].setTeacherId(str);
            cout << "修改成功" << endl;
            break;
        }
        case 3: {
            cout << "输入最大人员：";
            int max;
            cin >> max;
            courses[num].setMax(max);
            cout << "修改成功" << endl;
            break;
        }
        default:
            cout << "输入错误！" << endl;
    }
}

void CourseManager::findById() {
    cout << "输入课程编号：";
    string id;
    cin >> id;
    for (auto &s: courses) {
        if (s.getId() == id) {
            print(s);
            return;
        }
    }
    cout << "未找到" << endl;
}

void CourseManager::search() {
    cout << "输入名称：";
    string name;
    cin >> name;
    vector<Course> c;
    for (auto &s: courses) {
        if (s.getName().find(name) != -1 || teacher_link.getNameById(s.getTeacherId()).find(name) != -1)
            c.push_back(s);
    }
    print(c);

}

void CourseManager::addFromFile() {
    cout << "输入文件名：";
    string filename;
    cin >> filename;
    course_link.load(filename);
}



