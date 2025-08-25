#pragma one
#include"Student.h"
#include<vector>

class StudentStorage{
    public:
    void saveToCSV(const std::vector<Student>& students,const std::string& filename,int mode);
    static std::vector<Student> loadDataFromCSV(const std::string& filename);
};