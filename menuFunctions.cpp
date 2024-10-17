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

        node<string> *temp = totalClasses.getHead();
        while (temp)
        {
            for (int z = 0; z < size; z++)
            {
                if (result[z].getCode() == temp->getData())
                {
                    result[z].getEnrolled().insert(newStudent);
                }
            }
            temp = temp->getLink();
        }
        node<string> *temp2 = totalClassesWaitList.getHead();
        while (temp2)
        {
            for (int z = 0; z < size; z++)
            {
                if (result[z].getCode() == temp2->getData())
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
        cout << "[ " << courses[i].getCode() << " " << courses[i].getCourseName() << " (" << courses[i].getEnrolledCount() << ") ]";
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

Student findStudent(Course *courses, int size, int id)
{
    for (int i = 0; i < size; i++)
    {
        node<Student> *temp = courses[i].getEnrolled().getHead();
        while (temp && id != temp->getData().getId())
            temp = temp->getLink();
        if (!temp)
        {
            temp = courses[i].getWaitlist().getHead();
            while (temp && id != temp->getData().getId())
                temp = temp->getLink();
        }
        if (temp)
        {
            return temp->getData();
        }
    }
    Student notFound;
    notFound.setName("student not found");
    return notFound;
}
void menu1Printer(Course *courses, int size, int id, string name, bool isWaitlist)
{
    for (int i = 0; i < size; i++)
    {
        node<Student> *temp = (isWaitlist) ? courses[i].getWaitlist().getHead() : courses[i].getEnrolled().getHead();
        string key = (isWaitlist) ? "(W)   " : "(R)   ";

        while (temp && id != temp->getData().getId())
            temp = temp->getLink();
        if (temp)
            cout << key << courses[i].getCode() << "   " << courses[i].getCourseName() << endl;
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

    for (int i = 0; i < size; i++)
    {
        Student student = findStudent(courses, size, id);
        if (student.getName() != "student not found")
            ;
        {
            cout << "You registered " << student.getEnrolledCount() << " courses and waitlisted " << student.getWaitlistCount() << " courses. \n";
            break;
        }
    }
    menu1Printer(courses, size, id, name, false);
    menu1Printer(courses, size, id, name, true);
}
void updateCourseInfo(Course *courses, int size, Student student)
{
    int id = student.getId();
    for (int i = 0; i < size; i++)
    {
        node<Student> *temp = courses[i].getEnrolled().getHead();
        while (temp && id != temp->getData().getId())
            temp = temp->getLink();
        if (!temp)
        {
            temp = courses[i].getWaitlist().getHead();
            while (temp && id != temp->getData().getId())
                temp = temp->getLink();
        }
        if (temp)
        {
            temp->setData(student);
        }
    }
}
void menu2(Course *courses, int size)
{
    int id;
    string name, code, title;
    cout << "Enter your id : ";
    cin >> id;
    cout << "Enter your name : ";
    cin >> name;
    cout << "Enter course code : ";
    cin >> code;
    cout << "Enter course title : ";
    cin >> title;

    Student student = findStudent(courses, size, id);
    for (int i = 0; i < size; i++)
    {
        if (courses[i].getCode() == code && courses[i].getCourseName() == title)
        {
            if (courses[i].getEnrolledCount() == 10)
            {
                courses[i].setWaitListCount(courses[i].getWaitListCount() + 1);
                student.setWaitlistCount(student.getWaitlistCount() + 1);
                student.getWaitList().insert(courses[i].getCourseName());
                courses[i].getWaitlist().insert(student);

                cout << "You are on waitlist " << code << endl;
            }
            else
            {
                courses[i].setEnrolledCount(courses[i].getEnrolledCount() + 1);
                student.setEnrolledCount(student.getEnrolledCount() + 1);
                student.getCourses().insert(courses[i].getCourseName());
                courses[i].getEnrolled().insert(student);
                cout << "\nRegistration succeed\n";
            }
        }
    }
    updateCourseInfo(courses, size, student);
}
void menu3(Course *courses, int size)
{
    int id;
    string name, code, title;
    cout << "Enter your id : ";
    cin >> id;
    cout << "Enter your name : ";
    cin >> name;
    cout << "Enter course code : ";
    cin >> code;
    cout << "Enter course title : ";
    cin >> title;

    Student student = findStudent(courses, size, id);
    bool isWait = false;
    if (student.getCourses().deleteSpecific(code))
    {
        cout << "'" << title << "' is removed from your course list. \n";
        student.setEnrolledCount(student.getEnrolledCount() - 1);
    }
    else if (student.getWaitList().deleteSpecific(code))
    {
        cout << "You have been removed from the waitlist of '" << title << "'";
        student.setWaitlistCount(student.getWaitlistCount() - 1);
        isWait = true;
    }
    else
    {
        cout << " Course not found \n";
        return;
    }
    updateCourseInfo(courses, size, student);

    for (int i = 0; i < size; i++)
    {
        if (courses[i].getCode() == code && courses[i].getCourseName() == title)
        {
            if (!isWait)
            {
                courses[i].getEnrolled().deleteSpecific(student);
                if (courses[i].getWaitListCount() != 0)
                {
                    courses[i].setWaitListCount(courses[i].getWaitListCount() - 1);
                    courses[i].getEnrolled().insertHead(courses[i].getWaitlist().getHead()->getData());
                    courses[i].getWaitlist().deleteHead();
                }
                else
                {
                    courses[i].setEnrolledCount(courses[i].getEnrolledCount() - 1);
                }
            }
            else
            {
                courses[i].setWaitListCount(courses[i].getWaitListCount() - 1);
                courses[i].getWaitlist().deleteSpecific(student);
            }
        }
    }
}

void deleteCourse(linkedList<Student> course)
{
    node<Student>* temp = course.getHead();
    while (temp){
        temp->getData().getCourses().deleteAll();
        temp->getData().getWaitList().deleteAll();
        temp = temp->getLink();
    }
}
void deleteAll(Course *courses, int size)
{
    cout << "\nDeleting... \n\n";
    for (int i = 0; i < size; i++)
    {
        if (courses[i].getWaitListCount() != 0)
        {
            deleteCourse(courses[i].getWaitlist());
        }
        if (courses[i].getEnrolledCount() != 0)
        {
            deleteCourse(courses[i].getEnrolled());
        }
        courses[i].getWaitlist().deleteAll();
        courses[i].getEnrolled().deleteAll();
    }
    delete[] courses;
}
// cout << "\n\n\n here: ";
// cout << name << "<<<<name " << endl;
// printTotalClasses(totalClasses);