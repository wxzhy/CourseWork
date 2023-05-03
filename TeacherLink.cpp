//
// Created by Admin on 2023/5/2.
//

#include "TeacherLink.h"


void TeacherLink::add(string id, string name, string sex, string depart, string phone) {
    Teacher t(id, name, sex, depart, phone);
    link.push_back(t);

}

void TeacherLink::updatePassword(string id, string password) {
    for (auto it = link.begin(); it != link.end(); ++it) {
        if (it->getId() == id) {
            it->setPassword(password);
            return;
        }
    }

}
