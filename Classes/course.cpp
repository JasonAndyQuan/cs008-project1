#include "Course.h"

Course::Course(){
    this->title = "none";
    this->courseName = "none";
}
Course::Course(std::deque<Student>& enrolled, std::deque<Student>& waitlist, std::string courseName, std::string title, int waitCount, int enrolledCount){
    this->title = title;
    this->courseName = courseName;
    this->enrolled = enrolled;
    this->waitlist = waitlist;
}

// Course::~Course(){
    
// }

std::deque<Student> Course::getEnrolled() const{
    return this->enrolled;
}
std::deque<Student> Course::getWaitlist() const{
    return this->waitlist;
}
std::string Course::getCourseName() const{
    return this->courseName;  
}
std::string Course::getTitle() const{
    return this->title;
}
int Course::getWaitListCount() const{
    return this->waitlist.size();
}
int Course::getEnrolledCount() const{
    return this->enrolled.size();
}
void Course::setEnrolled(std::deque<Student>& enrolledNew) {
    this->enrolled = enrolledNew;
}
void Course::setWaitlist(std::deque<Student>& waitlistedNew){
    this->waitlist = waitlistedNew;
}
void Course::setCourseName(std::string name){
    this->courseName = name;
}
void Course::setTitle(std::string val){
    this->title = val;
}