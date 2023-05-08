//
// Created by Admin on 2023/5/3.
//

#include <iomanip>
#include "ScoreManager.h"

void ScoreManager::menu() {
    while (true) {
        Display::Head(">>管理模块>>成绩管理");
        cout << "     1.查看所有成绩" << endl;
        cout << "     2.删除成绩" << endl;
        cout << "     3.按课程查询" << endl;
        cout << "     4.按分数排序" << endl;
        cout << "     5.按学号排序" << endl;
        cout << "     6.从文件添加" << endl;
        cout << "     0.返回上级菜单" << endl;
        Display::Tail();
        cout << "请输入：";
        int op;
        cin >> op;
        switch (op) {
            case 0:
                return;
            case 1:
                showAll();
                break;
            case 2:
                del();
                break;
            case 3:
                queryByCourse();
            case 4: {
                score_link.sortByValue();
                Display::Result();
                cout << "排序成功" << endl;
                break;
            }
            case 5: {
                score_link.sortByStudentId();
                Display::Result();
                cout << "排序成功" << endl;
                break;
            }
            case 6:
                addFromFile();
                break;
            default:
                Display::Result();
                cout << "输入错误！" << endl;
        }
    }
}

void ScoreManager::showAll() {
    print(scores);

}

void ScoreManager::print(vector<Score> s) {
    if (s.empty()) {
        cout << "未找到！" << endl;
        return;
    }
    // 打印表头
    cout << "+------------+------------+-----------------+-------+" << endl;
    cout << "| " << setw(10) << "学号" << " | " << setw(10) << "姓名" << " | "
         << setw(15) << "课程名称" << " | " << setw(5) << "成绩" << " |" << endl;
    cout << "+------------+------------+-----------------+-------+" << endl;
    int n = 0;
    float sum = 0.0;
    // 遍历学生列表，打印每个学生的成绩信息
    for (auto &s: scores) {
        // 打印学生信息
        cout << "| " << left << setw(10) << s.getId() << " | " << left << setw(10)
             << student_link.getNameById(s.getId()) << " | " << left
             << setw(15) << course_link.getNameById(s.getCourseId()) << " | " << left << setw(5) << setprecision(3)
             << s.getValue() << " |"
             << endl;
        n++;
        sum += s.getValue();
        if (n % 20 == 0)
            system("pause>nul");
    }

    // 打印表尾
    cout << "+------------+------------+-----------------+-------+" << endl;
    cout << "共有" << n << "条记录" << endl;
    sum /= n;
    cout << "总平均分" << setprecision(3) << sum << endl;
    system("pause>nul");
}

void ScoreManager::del() {
    string cid, sid;
    cout << "输入课程编号：";
    cin >> cid;
    cout << "输入学生学号：";
    cin >> sid;
    for (auto it = scores.begin(); it != scores.end(); ++it) {
        if (it->getStudentId() == sid && it->getCourseId() == cid) {
            scores.erase(it);
            cout << "删除成功！" << endl;
            return;
        }
    }
    cout << "未找到" << endl;
}

void ScoreManager::queryByCourse() {
    string str;
    cout << "输入课程编号：";
    cin >> str;
    vector<Score> sc;
    for (auto &s: scores) {
        if (s.getCourseId() == str)
            sc.push_back(s);
    }
    print(sc);
}

void ScoreManager::addFromFile() {
    cout << "输入文件名：";
    string filename;
    cin >> filename;
    score_link.load(filename);
}
