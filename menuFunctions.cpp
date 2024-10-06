#include "Classes/course.cpp"
#include "Classes/student.cpp"
#include <fstream>
using namespace std;
#include <iostream>

Course* setUp(Course* courses, string courseFile, string enrollmentFile){

    ifstream infile;
    int size = 2;
    Course* result = new Course[size];
    infile.open(courseFile);
    while (!infile.eof()){
        string courseName, crn;
        int enroll, waitlist;
    }

    return result;

}
