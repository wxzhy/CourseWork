//
// Created by Wxyz on 2023/4/2.
//

#include "Student.h"
#include<fstream>

ofstream &operator<<(ofstream &out, Student &c) {
    out << c.id << '\t' << c.name << '\t' << c.password << '\t' << c.sex << '\t' << c.prof << '\t' << c.grade << endl;
    return out;
}


ifstream &operator>>(ifstream &in, Student &c) {
    in >> c.id >> c.name >> c.password >> c.sex >> c.prof >> c.grade;
    return in;
}
