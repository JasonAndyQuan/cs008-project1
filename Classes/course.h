#pragma once
#include <iostream>
#include "student.h"
#include <deque>

class Course {
    private: 
        std::string title;
        std::string courseName;

        std::deque<Student> enrolled;
        std::deque<Student> waitlist;
    public:
        Course();
        Course(std::deque<Student>&, std::deque<Student>&, std::string, std::string, int, int);
        // ~Course();

        std::deque<Student> getEnrolled() const;
        std::deque<Student> getWaitlist() const;
        std::string getCourseName() const;
        std::string getTitle() const;
        int getWaitListCount() const;
        int getEnrolledCount() const;

        void setEnrolled(std::deque<Student>&);
        void setWaitlist(std::deque<Student>&);

        void setCourseName(std::string);
        void setTitle(std::string);

};