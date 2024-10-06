#include "Course.h"

Course::Course(){
    this->crn = 0;
    this->courseName = "none";
}
Course::Course(std::deque<Student>& enrolled, std::deque<Student>& waitlist, std::string Course, int crn, int waitCount, int enrolledCount){
    this->crn = crn;
    this->courseName = Course;
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
int Course::getCrn() const{
    return this->crn;
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
void Course::setCrn(int num){
    this->crn = num;
    
}