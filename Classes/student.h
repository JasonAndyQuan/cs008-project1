#pragma once
#include <iostream>
// #include "course.h"
#include "linkedlist.cpp"

class Student
{
private:
    int id;
    std::string name;
    linkedList<std::string> waitlist;
    linkedList<std::string> courses;

public:
    Student();
    Student(int, std::string, linkedList<std::string> &, linkedList<std::string> &);

    int getId() const;
    std::string getName() const;
    linkedList<std::string> getCourses() const;
    linkedList<std::string> getWaitList() const;

    void setId(int);
    void setName(std::string);
    void setWaitlist(const linkedList<std::string>&);
    void setCourses(const linkedList<std::string>&);
};