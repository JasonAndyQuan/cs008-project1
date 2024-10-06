#include "Course.h"

Course::Course(){
    this->title = "none";
    this->courseName = "none";
}
Course::Course(std::string courseName, std::string title, int waitCount, int enrolledCount){
    this->title = title;
    this->courseName = courseName;
    this->enrolledCount = enrolledCount;
    this->waitListCount = waitCount;
}

linkedList<Student>& Course::getEnrolled(){
    return this->enrolled;
}
linkedList<Student>& Course::getWaitlist(){
    return this->waitlist;
}
std::string Course::getCourseName() const{
    return this->courseName;  
}
std::string Course::getTitle() const{
    return this->title;
}
int Course::getWaitListCount() const{
    return this->waitListCount;
}
int Course::getEnrolledCount() const{
    return this->enrolledCount;
}
void Course::setEnrolled(linkedList<Student>& enrolledNew) {
    this->enrolled = enrolledNew;
}
void Course::setWaitlist(linkedList<Student>& waitlistedNew){
    this->waitlist = waitlistedNew;
}
void Course::setCourseName(std::string name){
    this->courseName = name;
}
void Course::setTitle(std::string val){
    this->title = val;
}
void Course::setWaitListCount(int num){
    this->waitListCount = num;
}
void Course::setEnrolledCount(int num){
    this->enrolledCount = num;
}