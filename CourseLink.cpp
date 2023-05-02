//
// Created by Admin on 2023/5/2.
//

#include "CourseLink.h"

void CourseLink::add(string id, string teacherId, string name, string desc) {
    Course c(id,teacherId,name,desc);
    link.push_back(c);


}

void CourseLink::update(string id, string teacherId, string name, string desc) {
    for(auto it=link.begin();it!=link.end();++it){
        if(it->getId()==id) {
            it->setTeacherId(teacherId);
            it->setName(name);
            it->setDesc(desc);
        }
    }

}
