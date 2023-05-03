//
// Created by Admin on 2023/5/2.
//

#include "StudentLink.h"

void StudentLink::update(string id, string name, string sex, string prof, int grade) {
    for(auto it=link.begin(); it!=link.end();++it){
        if(it->getId()==id){
            it->setName(name);
            it->setSex(sex);
            it->setProf(prof);
            it->setGrade(grade);
        }
    }

}

int StudentLink::getNumById(string id) {
    for(auto it=link.begin(); it!=link.end();++it)
        if(it->getId()==id)
            return it-link.begin();
    return -1;
}
