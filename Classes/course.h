#pragma once
#include <iostream>
#include "student.h"
#include <deque>

class Course {
    private: 
        int crn;
        std::string courseName;

        std::deque<Student> enrolled;
        std::deque<Student> waitlist;
    public:
        Course();
        Course(std::deque<Student>&, std::deque<Student>&, std::string, int, int, int);
        ~Course();

        std::deque<Student> getEnrolled() const;
        std::deque<Student> getWaitlist() const;
        std::string getCourseName() const;
        int getCrn() const;
        int getWaitListCount() const;
        int getEnrolledCount() const;

        void setEnrolled(std::deque<Student>&);
        void setWaitlist(std::deque<Student>&);

        void setCourseName(std::string);
        void setCrn(int);

};