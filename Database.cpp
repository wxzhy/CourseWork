//
// Created by Admin on 2023/5/2.
//

#include "Database.h"

void Database::save() {
    student_link.save("student.txt");
    teacher_link.save("teacher.txt");
    course_link.save("course.txt");
    score_link.save("score.txt");

}

void Database::load() {
    student_link.load("student.txt");
    teacher_link.load("teacher.txt");
    course_link.load("course.txt");
    score_link.load("score.txt");
}
CourseLink Database::course_link;
StudentLink Database::student_link;
TeacherLink Database::teacher_link;
ScoreLink Database::score_link;