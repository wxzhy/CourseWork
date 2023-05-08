//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_DATABASE_H
#define COURSEWORK_DATABASE_H
#define courses course_link.link
#define teachers teacher_link.link
#define students student_link.link
#define scores score_link.link

#include "CourseLink.h"
#include "StudentLink.h"
#include "TeacherLink.h"
#include "ScoreLink.h"

class Database {
public://静态变量，存放向量
    static CourseLink course_link;
    static StudentLink student_link;
    static TeacherLink teacher_link;
    static ScoreLink score_link;

    static void save();

    static void load();
};



#endif //COURSEWORK_DATABASE_H
