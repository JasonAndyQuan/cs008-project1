#include "Classes/course.cpp"
#include "Classes/student.cpp"
#include <fstream>
using namespace std;
#include <iostream>
#include <vector>

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
        vector<string> totalClasses;
        vector<string> totalClassesWaitList;
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
        linkedList<string> classes;
        for (int p = 0; p < studEnrolled; p++)
        {
            infile >> courseName;
            classes.insert(courseName);
            totalClasses.push_back(courseName);
            // cout << "\n course is : " << courseName << endl;
        }
        int nextNumber;
        infile >> nextNumber;
        linkedList<string> studWaitList;
        if (nextNumber < 100)
        {
            for (int p = 0; p < nextNumber; p++)
            {
                infile >> courseName;
                studWaitList.insert(courseName);
                totalClassesWaitList.push_back(courseName);
                // cout << "\n COURSE is : " << courseName << endl;
            }
        }
        else
        {
            pass = true;
            id2 = nextNumber;
        }

        int waitlistCount = (nextNumber < 100) ? nextNumber : 0;
        Student newStudent(id, name, studWaitList, classes, studEnrolled, waitlistCount);

        for (string course : totalClasses)
        {
            for (int z = 0; z < size; z++)
            {
                if (result[z].getTitle() == course)
                    result[z].getEnrolled().insert(newStudent);
            }
        }
        for (string course : totalClassesWaitList)
        {
            for (int z = 0; z < size; z++)
            {
                if (result[z].getTitle() == course)
                    result[z].getWaitlist().insert(newStudent);
            }
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
        cout << "[ " << courses[i].getTitle() << " " << courses[i].getCourseName() << " (" << courses->getEnrolledCount() << ") ]";
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
linkedList<Student> getStudents (string file){
    linkedList<Student> list;
    ifstream infile;
    infile.open(file);
    int id2;
    bool pass = false;
    while (!infile.eof())
    {
        vector<string> totalClasses;
        vector<string> totalClassesWaitList;
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
        linkedList<string> classes;
        for (int p = 0; p < studEnrolled; p++)
        {
            infile >> courseName;
            classes.insert(courseName);
            totalClasses.push_back(courseName);
            // cout << "\n course is : " << courseName << endl;
        }
        int nextNumber;
        infile >> nextNumber;
        linkedList<string> studWaitList;
        if (nextNumber < 100)
        {
            for (int p = 0; p < nextNumber; p++)
            {
                infile >> courseName;
                studWaitList.insert(courseName);
                totalClassesWaitList.push_back(courseName);
                // cout << "\n COURSE is : " << courseName << endl;
            }
        }
        else
        {
            pass = true;
            id2 = nextNumber;
        }

        int waitlistCount = (nextNumber < 100) ? nextNumber : 0;
        Student newStudent(id, name, studWaitList, classes, studEnrolled, waitlistCount);
        list.insert(newStudent);
    }
    return list;
}
void menu1(linkedList<Student> students){
    int id;
    string name;
    cout << "\nEnter your id: ";
    cin >> id;
    cout << "Enter your Name: ";
    cin >> name;

    node<Student>* temp = students.getHead();
    while (temp && temp->getData().getId() != id)
        temp = temp->getLink();
    
    cout << "You registered " << temp->getData().getEnrolledCount() << " and waitlisted " <<temp->getData().getWaitlistCount() << " courses.";

}

// cout << "\n\n\n here: ";
// cout << name << "<<<<name " << endl;
// printTotalClasses(totalClasses);