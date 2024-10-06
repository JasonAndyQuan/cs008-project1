#pragma once
#include <iostream>
// #include "course.h"
#include "linkedlist.cpp"
#include <deque>

class Student
{
private:
    int id;
    std::string name;
    // linkedList<std::string> waitlist;
    // linkedList<std::string> courses;
    std::deque<std::string> waitlist;
    std::deque<std::string> courses;

    int enrolledCount;
    int waitListCount;


public:
    Student();
    Student(int, std::string, std::deque<std::string> &, std::deque<std::string> &, int, int);

    int getEnrolledCount() const;
    int getWaitlistCount() const;
    int getId() const;
    std::string getName() const;
    std::deque<std::string> getCourses() const;
    std::deque<std::string> getWaitList() const;

    void setId(int);
    void setName(std::string);
    void setWaitlist(const std::deque<std::string>&);
    void setCourses(const std::deque<std::string>&);
    void setEnrolledCount(int);
    void setWaitlistCount(int);
    friend std::ostream &operator<<(std::ostream &os, const Student &student);

};