#include <iostream>
class Student
{
private:
    int id;
    std::string name;

public:
    Student();
    Student(int, std::string);
    int getId();
    std::string getName();
    void setId(int);
    void setName(std::string);
};