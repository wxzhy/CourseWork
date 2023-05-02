//
// Created by Wxyz on 2023/4/2.
//

#include "Teacher.h"
#include<fstream>

ofstream &operator<<(ofstream &out, Teacher &c) {
    out << c.id << '\t' << c.name << '\t' << c.password << '\t' << c.sex << '\t' << c.depart << '\t' << c.phone << endl;
    return out;
}


ifstream &operator>>(ifstream &in, Teacher &c) {
    in >> c.id >> c.name >> c.password >> c.sex >> c.depart >> c.phone;
    return in;
}