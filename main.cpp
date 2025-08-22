#include<iostream>
#include"StudentService.h"

int main(){
    StudentService studentservice;
    int choice;
    do{
        cout<<"\n<=====Student Management=====>\n";
        cout<<"1: Add a new student"<<endl;
        cout<<"2: Remove student by ID\n";
        cout<<"3: Display all student\n";
        cout<<"4: Quit!"<<endl;
        cin>>choice;
        switch (choice){
            case 1:{
                int id,age;
                string name;
                double score;
                cout<<"Enter ID: "; cin>>id;cin.ignore();
                cout<<"Enter Name: "; getline(cin,name);
                cout<<"Enter age: "; cin>>age;
                cout<<"Enter Score: "; cin>>score;

                Student st(id,name,age,score);
                studentservice.addStudent(st);
                break;
            }
            case 2:{
                int id;
                cout<<"Enter ID"<<endl;cin>>id;
                if(studentservice.removeStudent(id)){
                    cout<<"Done !"<<endl;
                }
                else cout<<"Don't exist this student !"<<endl;
                break;
            }
            case 3:{
                studentservice.displayAll();
                break;
            }    
        }
    }   
    while(choice !=4);
}