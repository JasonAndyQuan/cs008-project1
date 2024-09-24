#include <iostream>
#include "node.h"

class course {
    private: 
        node* students;
        int crn;
        std::string courseName;
    public:
        course();
        course(node*, std::string, int);
        ~course();

        node* getStudents();
        std::string getCourseName();
        int getCrn();

        void setStudents(node*);
        void setcourseName(std::string);
        void setCrn(int);
};