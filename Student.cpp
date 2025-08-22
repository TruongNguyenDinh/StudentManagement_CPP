#include"Student.h"
#include<iostream>
//Constructor
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
void Student::setName(const string& newName){name = newName;}
void Student::setAge(int newAge){age = newAge;}
void Student::setScore(double newScore){score = newScore;}

void Student::display() const {
    cout << "id: " << id 
         << "\nname: " << name 
         << "\nage: " << age 
         << "\nscore: " << score << endl;
}
