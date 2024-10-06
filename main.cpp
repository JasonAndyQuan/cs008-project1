
#include "menuFunctions.cpp"
#include <iostream>

using namespace std;

int main()
{

    char input = 'y';
    string course, enrollment;
    // course.txt enrollment.txt
    cout << "Enter course filename : ";
    cin >> course;
    cout << "Enter enrollment filename : ";
    cin >> enrollment;

    Course *courses = setUp(course, enrollment);
    int size = getCourseSize(course);

    do
    {
        cout << "\n============== Menu ==============\n";
        cout << "1. View your registration\n";
        cout << "2. Course registration\n";
        cout << "3. Course cancellation\n";
        cout << "4. Print enrollment list including waitlist\n";
        cout << "5. Exit\n";
        cout << "---> Select : ";

        cin >> input;
        switch (input)
        {
        case ('1'):
            menu1(courses, size);
            break;
        case ('2'):
            /// asd
            break;
        case ('3'):
            /// asd
            break;
        case ('4'):
            menu4(courses, size);
            break;
        case ('5'):
            /// asd
            break;
        default:
            cout << "\n invalid input \n";
            break;
        }
    } while (input != 5);
    return 0;
}