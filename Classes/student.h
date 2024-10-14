#pragma once
#include <iostream>
// #include "course.h"
#include "linkedlist.cpp"
// #include <deque>

class Student
{
private:
    int id;
    std::string name;
    linkedList<std::string> waitlist;
    linkedList<std::string> courses;

    int enrolledCount;
    int waitListCount;


public:
    Student();
    Student(int, std::string, linkedList<std::string> &, linkedList<std::string> &, int, int);

    int getEnrolledCount() const;
    int getWaitlistCount() const;
    int getId() const;
    std::string getName() const;
    linkedList<std::string>& getCourses();
    linkedList<std::string>& getWaitList();

    void setId(int);
    void setName(std::string);
    void setWaitlist(const linkedList<std::string>&);
    void setCourses(const linkedList<std::string>&);
    void setEnrolledCount(int);
    void setWaitlistCount(int);
    friend std::ostream &operator<<(std::ostream &os, const Student &student);

};