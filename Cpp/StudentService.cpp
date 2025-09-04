#include"../Header/StudentService.h"
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

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
bool StudentService::isInteger(const string& s){
    int i = 0;
    if(s[0]=='-'|| s[0]=='+') i =1;
    for(;i<(int)s.size();i++){
        if(!isdigit(s[i])) return false;
    }
    return true;
}
Student* StudentService::findStudent(const string& s){
    if(s.empty()){
        return nullptr;
    } 
    else{
        if(isInteger(s)){
            int id = stoi(s);
            for(auto& st:students){
                if(st.getId() == id){
                    return &st;
                }
            }
            return nullptr;
        }
        else{
            for(auto& st:students){
                if(st.getName()==s){
                    return &st;
                }
            }
            return nullptr;
        }
    }
    return nullptr;
}
void StudentService::displayAll() const {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }
    for (const auto& s : students) {
        s.display();
    }
}
void StudentService::editName(int id,const string& newName){
    for(auto& st:students){
        if(st.getId()==id){
            st.setName(newName);
            cout<<"Done !"<<endl;
            return;
        }
    }
    cout<<"No student found with ID"<<endl;
}
void StudentService::editAge(int id,int newAge){
    for(auto& st:students){
        if(st.getId()==id){
            st.setAge(newAge);
            cout<<"Done"<<endl;
            return;
        }
    }
    cout<<"No student found with ID"<<endl;
}
void StudentService::editScore(int id,double newScore){
    for(auto& st:students){
        if(st.getId()==id){
            st.setScore(newScore);
            cout<<"Done"<<endl;
            return;
        }
    }
    cout<<"No student found with ID"<<endl;
}
vector<Student> StudentService::sortStudent(int mode){
    //Mode 1: sort by name
    if(mode == 1){
        stable_sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
        string nameA = a.getName();
        string nameB = b.getName();
        string lastA = nameA.substr(nameA.find_last_of(" ") + 1);
        string lastB = nameB.substr(nameB.find_last_of(" ") + 1);
        if (lastA == lastB) {
            return nameA < nameB;
        }
        return lastA < lastB;});
    }
    //Mode 2: sort by score
    else{
        sort(students.begin(),students.end(),
        [](const Student& a,const Student& b){
            return a.getScore()>b.getScore();
        });
    }
    return students;
}
vector<Student> StudentService::getStudent() const{
    return students;
}
void StudentService::pullData(vector<Student>& sts){
    students.insert(students.end(),
    make_move_iterator(sts.begin()),
    make_move_iterator(sts.end()));
    sts.clear();
}