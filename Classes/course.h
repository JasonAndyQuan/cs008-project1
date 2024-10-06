#pragma once
#include <iostream>
#include "student.h"
#include "linkedlist.h"

class Course {
    private: 
        std::string title;
        std::string courseName;
        linkedList<Student> enrolled;
        linkedList<Student> waitlist;
        int waitListCount;
        int enrolledCount;
        
    public:
        Course();
        Course(std::string, std::string, int, int);
        // ~Course();

        linkedList<Student>& getEnrolled() ;
        linkedList<Student>& getWaitlist() ;

        std::string getCourseName() const;
        std::string getTitle() const;

        int getWaitListCount() const;
        int getEnrolledCount() const;

        void setEnrolled(linkedList<Student>&);
        void setWaitlist(linkedList<Student>&);

        void setWaitListCount(int);
        void setEnrolledCount(int);


        void setCourseName(std::string);
        void setTitle(std::string);

};