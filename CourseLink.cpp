//
// Created by Admin on 2023/5/2.
//

#include "CourseLink.h"

void CourseLink::add(string id, string teacherId, string name, int num) {
    Course c(id,teacherId,name,num);
    link.push_back(c);

}

void CourseLink::update(string id, string teacherId, string name, string desc) {
    for(auto it=link.begin();it!=link.end();++it){
        if(it->getId()==id) {
            if(!teacherId.empty())
            it->setTeacherId(teacherId);
            if(!name.empty())
            it->setName(name);
        }
    }

}

vector<int> CourseLink::getNumByTeacherId(string id) {
    vector<int> nums;
    for (auto it = link.begin(); it != link.end(); ++it) {
        if (it->getId() == id)
            nums.push_back(it - link.begin());
    }
    return nums;

}

string CourseLink::getTeacherId(string id) {
    for (auto &s: link) {
        if (s.getId() == id) {
            return id;
        }
    }
    return "";
}

void CourseLink::addCurrent(string id) {
    for (auto &it: link) {
        if (it.getId() == id) {
            it.addCurrent();
            return;
        }
    }

}
