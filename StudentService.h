#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H

#include"Student.h"
#include<vector>
using namespace std;
class StudentService{
    private:
    vector<Student> students;
    public:
    void addStudent(const Student& s);
    bool removeStudent(int id);
    void displayAll() const;

};
#endif