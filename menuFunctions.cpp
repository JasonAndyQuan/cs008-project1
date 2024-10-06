#include "Classes/course.cpp"
#include "Classes/student.cpp"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

Course *setUp(string courseFile, string enrollmentFile)
{
    ifstream infile;
    int size = 1;
    Course *result = new Course[size];
    infile.open(courseFile);
    int i = 0;
    while (!infile.eof())
    {
        string courseName, title;
        int enroll, waitlist;
        infile >> title >> courseName >> enroll >> waitlist;
        Course newCourse(courseName, title, waitlist, enroll);
        result[i] = newCourse;
        i++;
        if (i == size && !infile.eof())
        {
            size++;
            Course *newResult = new Course[size];
            for (int z = 0; z < i; z++)
            {
                newResult[z] = result[z];
            }
            delete[] result;
            result = newResult;
        }
    }
    size = i;
    // for (int j = 0; j < i; j++){
    //     cout << result[j].getCourseName() << endl;
    // }
    infile.close();
    infile.open(enrollmentFile);

    int id2;
    bool pass = false;

    while (!infile.eof())
    {
        linkedList<std::string> totalClasses;
        linkedList<std::string> totalClassesWaitList;

        int id, studEnrolled, studWait;
        string courseName, name;
        if (pass)
        {
            infile >> name >> studEnrolled;
            pass = false;
            id = id2;
        }
        else
        {
            infile >> id >> name >> studEnrolled;
        }
        // cout << "\n----------" << name << "--------------\n";
        for (int p = 0; p < studEnrolled; p++)
        {
            infile >> courseName;
            totalClasses.insert(courseName);
            // cout << "\n course is : " << courseName << endl;
        }
        int nextNumber;
        infile >> nextNumber;
        if (nextNumber < 100)
        {
            for (int p = 0; p < nextNumber; p++)
            {
                infile >> courseName;
                totalClassesWaitList.insert(courseName);
                // cout << "\n COURSE is : " << courseName << endl;
            }
        }
        else
        {
            pass = true;
            id2 = nextNumber;
        }

        int waitlistCount = (nextNumber < 100) ? nextNumber : 0;
        Student newStudent(id, name, totalClassesWaitList, totalClasses, studEnrolled, waitlistCount);

        node<string>* temp = totalClasses.getHead();
        while (temp){
            for (int z = 0; z < size; z++)
            {
                if (result[z].getTitle() == temp->getData()){
                    result[z].getEnrolled().insert(newStudent);}
            }
            temp = temp->getLink();
        }
        node<string>* temp2 = totalClassesWaitList.getHead();
        while (temp2){
            for (int z = 0; z < size; z++)
            {
                if (result[z].getTitle() == temp2->getData())
                    result[z].getWaitlist().insert(newStudent);
            }
            temp2 = temp2->getLink();
        }
    }
    // for (int j = 0; j < i; j++){
    //     cout << result[j].getCourseName() << " : ";
    //     result[j].getEnrolled().printList();
    //     cout << endl;
    // }
    return result;
}

int getCourseSize(string file)
{
    ifstream infile;
    infile.open(file);
    int count = 0;
    string take;
    while (!infile.eof())
    {
        count++;
        infile >> take >> take >> take >> take;
    }
    return count;
}

void menu4(Course *courses, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[ " << courses[i].getTitle() << " " << courses[i].getCourseName() << " (" << courses[i].getEnrolledCount() << ") ]";
        cout << "\n--------------------------------\n";
        courses[i].getEnrolled().printStudents();
        cout << endl;
        if (courses[i].getWaitListCount() != 0)
        {
            cout << " < WaitList (" << courses[i].getWaitListCount() << ") > \n";
            courses[i].getWaitlist().printStudents();
            cout << endl;
        }
    }
}

void menu1Printer(Course *courses,int size, int id, string name, bool isWaitlist)
{
    for (int i = 0; i < size; i++)
    {
        node<Student> *temp = (isWaitlist) ? courses[i].getWaitlist().getHead() : courses[i].getEnrolled().getHead();
        string key = (isWaitlist) ? "(W)   " : "(R)   ";

        while (temp && id != temp->getData().getId())
            temp = temp->getLink();
        if (temp)
            cout << key << courses[i].getTitle() << "   " << courses[i].getCourseName() << endl;
    }
}
void menu1(Course *courses, int size)
{
    int id;
    string name;
    cout << "\nEnter your id: ";
    cin >> id;
    cout << "Enter your Name: ";
    cin >> name;

    menu1Printer(courses, size, id, name, false);
    menu1Printer(courses, size, id, name, true);
}

// cout << "\n\n\n here: ";
// cout << name << "<<<<name " << endl;
// printTotalClasses(totalClasses);