//
// Created by Wxyz on 2023/4/2.
//

#include "Score.h"
#include<fstream>

ofstream &operator<<(ofstream &out, Score &c) {
    out << c.studentId << '\t' << c.courseId << '\t' << c.value << endl;
    return out;
}

ifstream &operator>>(ifstream &in, Score &c) {
    in >> c.studentId >> c.courseId >> c.value;
    return in;
}
