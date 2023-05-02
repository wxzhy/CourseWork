//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_FILEUTILS_H
#define COURSEWORK_FILEUTILS_H
#include <fstream>
#include "Score.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

using namespace std;
class FileUtils {
public:
    vector<Student> students;
    vector<Course> courses;
    vector<Teacher> teachers;
    vector<Score> scores;
    void load() {
        ifstream file("student.txt");
        while(!file.eof()) {
            Student s;
            file>>s;
            students.push_back(s);
        }
        file.close();
        file.open("teacher.txt");
        while(!file.eof()) {
            Teacher t;;
            file>>t;
            teachers.push_back(t);
        }
        file.close();
        file.open("score.txt");
        while(!file.eof()) {
            Score c;
            file>>c;
            scores.push_back(c);
        }
        file.close();
        file.open("courses.txt");
        while(!file.eof()) {
            Course r;
            file>>r;
            courses.push_back(r);
        }
        file.close();
    }
    void save(){
        ofstream file("student.txt");
        for(auto s:students){
            file<<s;
        }
        file.close();
        file.open("course.txt");
        for(auto s:courses){
            file<<s;
        }
        file.close();
        file.open("teacher.txt");
        for(auto s:teachers){
            file<<s;
        }
        file.close();
        file.open("scores.txt");
        for(auto s:scores){
            file<<s;
        }
        file.close();
    }
};


#endif //COURSEWORK_FILEUTILS_H
