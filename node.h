#include "student.h"
class node{
    private: 
        node* link;
        Student student;
    public:
        ~node();
        node();
        node(Student, node*);
        Student getStudent();
        node* getLink();
        void setLink(node*);
        void setStudent(Student);

};