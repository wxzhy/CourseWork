//
// Created by Wxyz on 2023/4/2.
//

#include "Course.h"
#include<fstream>

ofstream &operator<<(ofstream &out, Course &c) {
    out << c.id << '\t' << c.name << '\t' << c.teacherId << '\t' << c.desc << endl;
    return out;
}

ifstream &operator>>(ifstream &in, Course &c) {
    in >> c.id >> c.name >> c.teacherId >> c.desc;
    return in;
}
