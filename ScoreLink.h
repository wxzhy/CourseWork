//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_SCORELINK_H
#define COURSEWORK_SCORELINK_H


#include "Score.h"
#include "Link.h"

class ScoreLink : public Link<Score> {//ScoreLink类的声明
public:
    vector<Score> getScoreByStudentId(string studentId);//按学号查询
    vector<Score> getScoreByCourseId(string courseId);//按课程查询
    vector<int> getScoreNumByCourseId(string courseId);//
    vector<int> getScoreNumByStudentId(string studentId);

    void add(string studentId, string courseId, float value);//添加
    void deleteByStudentId(string studentId);//按照学号删除
    bool ifExist(string studentId, string courseId);//检查是否存在
    void add(Score s);

    ScoreLink() {}

    void del(string studentId, string courseId);//删除知道分数
    void sortByValue();//按分数高低排序
    void sortByStudentId();//按照学号排序
    void sortByCourseId();//按照课程id排序
};


#endif //COURSEWORK_SCORELINK_H
