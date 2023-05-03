//
// Created by Admin on 2023/5/2.
//

#include "ScoreLink.h"

vector<Score> ScoreLink::getScoreByStudentId(string studentId) {
    vector<Score> s;
    for(auto& score : link){
        if(score.getStudentId() == studentId)
            s.push_back(score);

    }
    return s;
}

vector<Score> ScoreLink::getScoreByCourseId(string courseId) {
    vector<Score> s;
    for(auto& score : link){
        if(score.getCourseId() == courseId)
            s.push_back(score);

    }
    return s;
}

void ScoreLink::add(string studentId, string courseId, float value) {
    Score s(studentId, courseId, value);
    link.push_back(s);

}

void ScoreLink::del(string studentId, string courseId) {
    for(auto it=link.begin(); it!=link.end();++it){
        if(it->getCourseId() == courseId&&it->getStudentId() == studentId)
           link.erase(it);
    }

}

vector<int> ScoreLink::getScoreNumByCourseId(string courseId) {
    vector<int> n;
    for(auto it=link.begin(); it!=link.end();++it){
        if(it->getCourseId() == courseId)
            n.push_back(it-link.begin());
    }
    return n;
}

vector<int> ScoreLink::getScoreNumByStudentId(string studentId) {
    vector<int> n;
    for(auto it=link.begin(); it!=link.end();++it){
        if(it->getStudentId() == studentId)
            n.push_back(it-link.begin());
    }
    return n;
}
