#include <student.h>
#include <iostream>

    Student::Student(){
        this->name = "none";
        this->id = 0;
    }
    Student::Student(int id, std::string name){
        this->name = name;
        this->id = id;    
    }
    int Student::getId(){
        return this->id;
    }
    std::string Student::getName(){
        return this->name;
    }
    void Student::setId(int i){
        this->id = i;
    }
    void Student::setName(std::string s){
        this->name = s;
    }
