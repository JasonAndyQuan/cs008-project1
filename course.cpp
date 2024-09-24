    #include "course.h";
    
    course::course(){
        this->crn = 0;
        this->courseName = "none";
        this->students = NULL;
    }
    course::course(node* s, std::string n , int c){
        this->crn = c;
        this->courseName = n;
        this->students = s;
    }
    course::~course(){
        delete this->students;
    }

    node* course::getStudents(){
        return students;
    }
    std::string course::getCourseName(){
        return this->courseName;
    }
    int course::getCrn(){
        return this->crn;
    }

    void course::setStudents(node* s){
        this->students = s;
    }
    void course::setcourseName(std::string n){
        this->courseName = n;
    }
    void course::setCrn(int c){
        this->crn = c;
    }




    