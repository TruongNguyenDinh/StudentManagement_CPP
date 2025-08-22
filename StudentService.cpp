#include"StudentService.h"
#include<iostream>

void StudentService::addStudent(const Student& s){
    students.push_back(s);
}

bool StudentService::removeStudent(int id){
    for(auto it = students.begin();it!=students.end();){
        if(it->getId() == id){
            it = students.erase(it);
            return true;
        }
        else{
            it++;
        }
    }
    return false;
}
void StudentService::displayAll() const {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }
    for (const auto& s : students) {
        s.display();
        cout << "-----------------\n";
    }
}