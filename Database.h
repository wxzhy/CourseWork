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

class Database {//DatabaseLink类的声明
public://静态变量，存放向量
    static CourseLink course_link;//课程
    static StudentLink student_link;//学生
    static TeacherLink teacher_link;//教师
    static ScoreLink score_link;//成绩
    static void save();//保存到文件
    static void load();//从文件读取
};



#endif //COURSEWORK_DATABASE_H
