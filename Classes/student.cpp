#include "student.h"
#include <iostream>

Student::Student(){
    this->name = "none";
}
Student::Student(int id, std::string name, linkedList<std::string> &waitlist, linkedList<std::string> &courses) {
    this->id = id;
    this->name = name;
    this->waitlist = waitlist;
    this->courses = courses;
}

int Student::getId() const{
    return this->id;
}
std::string Student::getName() const{
    return this->name;
}
linkedList<std::string> Student::getCourses() const{
    return this->courses;
}
linkedList<std::string> Student::getWaitList() const{
    return this->waitlist;
}
void Student::setId(int id){
    this->id = id;
}
void Student::setName(std::string name){
    this->name = name;
}
void Student::setWaitlist(const linkedList<std::string>& waitlist){
    this->waitlist = waitlist;
}
void Student::setCourses(const linkedList<std::string>& courses){
    this->courses = courses;
}