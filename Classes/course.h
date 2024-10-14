#pragma once
#include <iostream>
#include "student.h"
#include "linkedlist.h"

class Course {
    private: 
        std::string code;
        std::string courseName;
        linkedList<Student> enrolled;
        linkedList<Student> waitlist;
        int waitListCount;
        int enrolledCount;
        
    public:
        Course();
        Course(std::string, std::string, int, int);

        linkedList<Student>& getEnrolled() ;
        linkedList<Student>& getWaitlist() ;

        std::string getCourseName() const;
        std::string getCode() const;

        int getWaitListCount() const;
        int getEnrolledCount() const;

        void setEnrolled(linkedList<Student>&);
        void setWaitlist(linkedList<Student>&);

        void setWaitListCount(int);
        void setEnrolledCount(int);


        void setCourseName(std::string);
        void setCode(std::string);

};