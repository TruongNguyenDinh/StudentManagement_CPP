#include"../Header/StudentStorage.h"
#include<fstream>
#include<iostream>
#include<sstream>

void StudentStorage::saveToCSV(const std::vector<Student>& students,const string& filename,int mode){
    const std::string filePath = "../Storage/"+filename;
    std::ofstream file;
    if(mode == 1){ // save data with override
       file.open(filePath);
    }
    else{
        file.open(filePath,std::ios::app);
    }
    if(file.is_open()){
        std::cerr<<"Cannot open this file\n";
        return;
    }
    if(mode == 1){
        file<<"id,name,age,score\n";
    }
    for(const auto& st:students){
        file<<st.getId()<<","<<st.getName()<<","<<st.getAge()<<","<<st.getScore()<<endl;
    }
    file.close();
    std::cout<<"Done !\n";
}

std::vector<Student> StudentStorage::loadDataFromCSV(const string& filename){
    vector<Student> students;
    std::string filePath = "../Storage"+filename+".csv";
    std::ifstream file(filePath);

    if(!file.is_open()){
        std::cerr<<"Cannot open this file\n";
    }
    std::string line;
    std::getline(file, line);
    while(std::getline(file,line)){
        std::stringstream ss(line);
        Student st;
        std::string tmp;
        std::getline(ss,tmp,','); st.setID(std::stoi(tmp));
        std::getline(ss,tmp,','); st.setName(tmp);
        std::getline(ss,tmp,','); st.setAge(std::stoi(tmp));
        std::getline(ss,tmp,','); st.setScore(std::stod(tmp));
        students.push_back(st);
    }
    return students; 
}