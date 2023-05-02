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

    void add(string studentId, string courseId, float value);

public:
    ScoreLink() {}
    void del(string studentId, string courseId);

};


#endif //COURSEWORK_SCORELINK_H
