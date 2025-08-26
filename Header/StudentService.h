#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H

#include"Student.h"
#include<vector>
using namespace std;
class StudentService{
    private:
    vector<Student> students;
    bool isInteger(const string& s);
    static int autoGID;
    public:
    void addStudent(const Student& s);
    bool removeStudent(int id);
    void displayAll() const;
    Student* findStudent(const string& s);
    void editName(int id,const string& newName);
    void editAge(int id,int newAge);
    void editScore(int id,double newScore);
    vector<Student> sortStudent(int mode);
    vector<Student> getStudent() const;

};
#endif