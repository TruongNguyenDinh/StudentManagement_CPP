#include<iostream>
#include"../Header/StudentService.h"
StudentService studentservice;
void editMode(int mode,int id){
    switch(mode){
        case 1:{
            cout<<"Enter newname: ";cin.ignore();
            string newName;getline(cin,newName);
            studentservice.editName(id,newName);
            break;
        }
        case 2:{
            cout<<"Enter new age: ";
            int newAge;cin>>newAge;
            studentservice.editAge(id,newAge);
            break;
        }
        case 3:{
            cout<<"Enter new score: ";
            double newScore;cin>>newScore;
            studentservice.editScore(id,newScore);
        }
        case 4: break;
    }

}

void infomation(){
    cout<<
    "\n\n----------------Student Management----------------\n"<<
    "This is a simple problem to practice C++ language.\n"<<
    "If you want to contribute or help to make this problem more complete,\n"<<
    "You can contact with me.I think it will be a great motivation\n"<<
    "to help me develop and learn more.\nThank you!\n"<<
    "By: Nguyễn Đình Trường\n";
}

int isSafe(const string& tmp){
    try{
        return stoi(tmp);
    }
    catch(invalid_argument){
        return 0;
    }
    catch(out_of_range){
        return 0;
    }
    return 0;
}
int main(){
    int choice;
    string tmp;
    bool ok;
    do{
        cout<<"\n<=====Student Management=====>\n";
        cout<<"1: Add new student"<<endl;
        cout<<"2: Remove student by ID\n";
        cout<<"3: Display all student\n";
        cout<<"4: Find Student\n";
        cout<<"5: Edit Student\n";
        cout<<"6: Infomation\n";
        cout<<"7: Quit!"<<endl;
        cout<<"-----------------\n";
        cout<<"Enter you choice: ";
        cin>>tmp;
        choice = isSafe(tmp);
        if(choice == 0 || choice <0 || choice > 7){
            cout<<"Invalid input!\n";
        }
        else{
            switch (choice){
                case 1:{
                    cout<<"<=====Add Mode=====>\n";
                    int n; 
                    cout<<"Enter the number of students: ";cin>>n;
                    for (int i = 0;i<n;i++){
                        int id,age;
                        string name;
                        double score;cin.ignore();
                        cout<<"Enter Name: "; getline(cin,name);
                        cout<<"Enter age: ";cin>>age;
                        cout<<"Enter Score: "; cin>>score;
                        Student st(name,age,score);
                        studentservice.addStudent(st);
                        cout<<"------------------------\n";
                    }
                    cout<<"Break add mode\n";   
                    break;
                }
                case 2:{
                    cout<<"<=====Remove Mode=====>\n";
                    int id;
                    cout<<"Enter ID"<<endl;cin>>id;
                    if(studentservice.removeStudent(id)){
                        cout<<"Done !"<<endl;
                    }
                    else cout<<"Don't exist this student !"<<endl;
                    break;
                }
                case 3:{
                    cout<<"<===== INFORMATION OF ALL STUDENT=====>\n";
                    printf("%-5s %-25s %-5s %-6s\n", "ID", "Name", "Age", "Score");
                    studentservice.displayAll();
                    break;
                }
                case 4:{
                    cout<<"<===== Find Mode =====>\n";
                    cin.ignore();
                    cout<<"Enter ID or Name: ";
                    string inp;getline(cin,inp);
                    Student* st = studentservice.findStudent(inp);
                    if(!st){
                        cout<<"No student found with ID or Name!\n";
                        
                    }
                    else{
                        printf("ID: %d\nName: %s\n Age: %d\nScore: %.2f\n",st->getId(),st->getName().c_str(),st->getAge(),st->getScore());
                    }
                    break;
                }
                case 5:{
                    bool continueEditMode = true;
                    while(continueEditMode){
                        int id;
                        cout<<"<=====Edit Mode=====>"<<endl;
                        cout<<"Enter ID: ";cin>>id;
                        Student* st = studentservice.findStudent(to_string(id)); 
                        if(!st){
                            cout<<"No student found with ID\n";
                            cout<<"Do you want to continue edit ?\n";
                            cout<<"1: No\nPress anything: Yes\n";
                            int c;cin>>c;
                            if(c == 1) break;
                            else continue;
                        }
                        else{
                            bool isBreak = false;
                            do{
                                cout<<st->getName()<<" "<<st->getAge()<<" "<<st->getScore()<<endl;
                                cout<<"1:Edit name\n";
                                cout<<"2:Edit age\n";
                                cout<<"3:Edit score\n";
                                cout<<"4:Quit mode\n";
                                cin>>choice;
                                if(choice == 4){
                                    isBreak = true;
                                }
                                else{
                                    editMode(choice,id);
                                    cout<<"Do you want to continue edit ?\n";
                                    cout<<"1: No\n2: Press anything\n";
                                    int isCon;cin>>isCon;
                                    if(isCon==1) isBreak=true;
                                }  
                            }while(isBreak==false);
                            break;
                        }
                    }
                    
                }
                case 6:{
                    infomation();
                    break;
                }
            }
        }
        
    }   
    while(choice !=7);
}