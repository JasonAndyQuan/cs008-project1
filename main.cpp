#include "menuFunctions.cpp"
#include <iostream>

using namespace std;

//do menu 1 and 4
int main(){

    char input = 'y';
    string course, enrollment;

    cout << "Enter course filename : ";
    cin >> course;
    cout << "Enter enrollment filename : ";
    cin >> enrollment;

    do {
        cout << "\n============== Menu ==============\n";
        cout << "1. View your registration\n";
        cout << "2. Course registration\n";
        cout << "3. Course cancellation\n";
        cout << "4. Print enrollment list inclusing waitlist\n";
        cout << "5. Exit\n";
        cout << "---> Select : ";

        cin >> input;
        switch (input){
            case ('1'):
                break;
            case ('2'):
                ///asd
                break;
            case ('3'):
                ///asd
                break;
            case ('4'):
                ///asd
                break;
            case ('5'):
                ///asd
                break;
            default:
                cout << "\n invalid input \n";
                break;
            }
    } while (input != 5);
}