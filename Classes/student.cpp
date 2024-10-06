#include "student.h"
#include <iostream>

Student::Student(){
    this->name = "none";
    // this->courses = nullptr;
    // this->waitlist = nullptr;
}
Student::Student(int id, std::string name, std::deque<std::string> &waitlist, std::deque<std::string> &courses, int num1, int num2) {
    this->id = id;
    this->name = name;
    this->waitlist = waitlist;
    this->courses = courses;
    this->enrolledCount = num1;
    this->waitListCount = num2;
}
std::ostream &operator<<(std::ostream &os, const Student &student)
{
    os << student.name;
    return os;
}
int Student::getId() const{
    return this->id;
}
std::string Student::getName() const{
    return this->name;
}
std::deque<std::string> Student::getCourses() const{
    return this->courses;
}
std::deque<std::string> Student::getWaitList() const{
    return this->waitlist;
}
void Student::setId(int id){
    this->id = id;
}
void Student::setName(std::string name){
    this->name = name;
}
void Student::setWaitlist(const std::deque<std::string>& waitlist){
    this->waitlist = waitlist;
    this->waitListCount = waitlist.size();
}
void Student::setCourses(const std::deque<std::string>& courses){
    this->courses = courses;
    this->enrolledCount = courses.size();
}
void Student::setEnrolledCount(int count) {
    this->enrolledCount = count;
}

void Student::setWaitlistCount(int count) {
    this->waitListCount = count;
}

int Student::getEnrolledCount() const {
    return this->enrolledCount;
}

int Student::getWaitlistCount() const {
    return this->waitListCount;
}