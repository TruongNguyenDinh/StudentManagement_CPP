#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;

class Student{
    private:
    static int autoGId;
    int id;
    string name;
    int age;
    double score;
    public:
    // Constructor
    Student(){}
    Student(string name,int age, double score);
    Student(int id, string name, int age, double score);

    //getter & setter
    int getId() const;
    string getName() const;
    int getAge() const;
    double getScore() const;

    void setID(int addid);
    void setName(const string& newName);
    void setAge(int newAge);
    void setScore(double newScore);

    void display() const ;
};
#endif