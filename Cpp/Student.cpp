#include"../Header/Student.h"
#include<iostream>
//Constructor
Student::Student(string name, int age,double score){
    this->id = Student::autoGId++;
    this->name = name;
    this->age = age;
    this->score = score;
}
Student::Student(int id,string name,int age,double score){
    this->id = id;
    this->name = name;
    this->age = age;
    this->score = score;
}
//getter
int Student::getId() const {return id;}
string Student::getName() const {return name;}
int Student::getAge() const {return age;}
double Student::getScore() const {return score;}
//setter
int Student::autoGId=1;
void Student::setName(const string& newName){name = newName;}
void Student::setAge(int newAge){age = newAge;}
void Student::setScore(double newScore){score = newScore;}

void Student::display() const {
    printf("%-5d %-25s %-5d %-6.2f\n", id, name.c_str(), age, score);
}

