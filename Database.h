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

class Database {//DatabaseLink�������
public://��̬�������������
    static CourseLink course_link;//�γ�
    static StudentLink student_link;//ѧ��
    static TeacherLink teacher_link;//��ʦ
    static ScoreLink score_link;//�ɼ�
    static void save();//���浽�ļ�
    static void load();//���ļ���ȡ
};



#endif //COURSEWORK_DATABASE_H
