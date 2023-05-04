//
// Created by Admin on 2023/5/2.
//

#include "ScoreLink.h"
#include <algorithm>

vector<Score> ScoreLink::getScoreByStudentId(string studentId) {
    vector<Score> s;
    for (auto &score: link) {
        if (score.getStudentId() == studentId)
            s.push_back(score);

    }
    return s;
}

vector<Score> ScoreLink::getScoreByCourseId(string courseId) {
    vector<Score> s;
    for (auto &score: link) {
        if (score.getCourseId() == courseId)
            s.push_back(score);

    }
    return s;
}

void ScoreLink::add(string studentId, string courseId, float value) {
    Score s(studentId, courseId, value);
    link.push_back(s);

}

void ScoreLink::del(string studentId, string courseId) {
    for (auto it = link.begin(); it != link.end(); ++it) {
        if (it->getCourseId() == courseId && it->getStudentId() == studentId)
            link.erase(it);
    }

}

vector<int> ScoreLink::getScoreNumByCourseId(string courseId) {
    vector<int> n;
    for (auto it = link.begin(); it != link.end(); ++it) {
        if (it->getCourseId() == courseId)
            n.push_back(it - link.begin());
    }
    return n;
}

vector<int> ScoreLink::getScoreNumByStudentId(string studentId) {
    vector<int> n;
    for (auto it = link.begin(); it != link.end(); ++it) {
        if (it->getStudentId() == studentId)
            n.push_back(it - link.begin());
    }
    return n;
}

void ScoreLink::deleteByStudentId(string studentId) {
    for (auto it = link.begin(); it != link.end(); it++)
        if (it->getStudentId() == studentId)
            link.erase(it);
}

void ScoreLink::sortByValue() {
    sort(link.begin(), link.end(),
         [](Score &s1, Score &s2) { return s1.getId() > s2.getId(); });

}

void ScoreLink::sortByStudentId() {
    sort(link.begin(), link.end(),
         [](Score &s1, Score &s2) { return s1.getStudentId() < s2.getStudentId(); });
}

void ScoreLink::sortByCourseId() {
    sort(link.begin(), link.end(),
         [](Score &s1, Score &s2) { return s1.getCourseId() < s2.getCourseId(); });
}

bool ScoreLink::ifExist(string studentId, string courseId) {
    for (auto &s: link)
        if (s.getStudentId() == studentId && s.getCourseId() == courseId)
            return true;
    return false;
}

void ScoreLink::add(Score s) {
    if (ifExist(s.getStudentId(), s.getCourseId()))
        return;
    else
        link.push_back(s);
}
