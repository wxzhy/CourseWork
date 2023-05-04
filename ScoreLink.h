//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_SCORELINK_H
#define COURSEWORK_SCORELINK_H


#include "Score.h"
#include "Link.h"

class ScoreLink : public Link<Score> {
public:
    vector<Score> getScoreByStudentId(string studentId);

    vector<Score> getScoreByCourseId(string courseId);

    vector<int> getScoreNumByCourseId(string courseId);

    vector<int> getScoreNumByStudentId(string studentId);

    void add(string studentId, string courseId, float value);

    void deleteByStudentId(string studentId);

    bool ifExist(string studentId, string courseId);

    void add(Score s);

public:
    ScoreLink() {}

    void del(string studentId, string courseId);

    void sortByValue();

    void sortByStudentId();

    void sortByCourseId();

};


#endif //COURSEWORK_SCORELINK_H
