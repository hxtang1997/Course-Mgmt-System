#include "../headers/Menu.h"
#include "../headers/Register.h"

void Menu::getWelcomeMenu()
{
    cout << "=========Course Management System=========" << endl;
    cout << "Welcome to the course management system" << endl;
    cout << "1. Login" << endl;
    cout << "2. Sign up (Student)" << endl;
    cout << "3. Sign up (Teacher)" << endl;
    cout << "0. Exit" << endl;
}

void Menu::getStudentMenu()
{
    cout << "=========STUDENT MENU=========" << endl;
    cout << "1. View all courses" << endl;
    cout << "2. Enroll into a course (Please note the Course ID for enrollment)" << endl;
    cout << "3. View enrolled course" << endl;
    cout << "4. Withdraw from course" << endl;
    cout << "5. View profile" << endl;
    cout << "0. Exit" << endl;
}

void Menu::getCourseMenu()
{
    cout << "=========COURSE MENU=========" << endl;
    //loop through course file
}

void Menu::getTeacherMenu()
{
    cout << "=========TEACHER MENU=========" << endl;
    cout << "1. View courses I teach" << endl;
    cout << "2. Start a new course" << endl;
    cout << "3. View profile" << endl;
    cout << "0. Exit" << endl;
}

void Menu::getRegistrationMenu(string role)
{
    cout << "=========REGISTRATION=========" << endl;
    Register r;
    r.Registration(role);
}