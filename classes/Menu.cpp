#include "../headers/Menu.h"
#include "../headers/Register.h"
#include "../headers/Login.h"

void Menu::getWelcomeMenu()
{
    cout << "=========COURSE MANAGEMENT SYSTEM=========" << endl;
    cout << "Welcome to the course management system" << endl;
    cout << "1. Login" << endl;
    cout << "2. Sign up (Student)" << endl;
    cout << "3. Sign up (Teacher)" << endl;
    cout << "0. Quit" << endl;
    cout << "What would you like to do: ";
}

void Menu::getLoginMenu(){
    cout << "=========LOGIN=========" << endl;
    cout << "Welcome to the course management system" << endl;
}

void Menu::getStudentMenu()
{
    cout << "=========STUDENT MENU=========" << endl;
    cout << "1. View all courses" << endl;
    cout << "2. Enroll into a course (Please note the Course ID for enrollment)" << endl;
    cout << "3. View enrolled course" << endl;
    cout << "4. Withdraw from course" << endl;
    cout << "5. View profile" << endl;
    cout << "0. Logout" << endl;
    cout << "What would you like to do: ";
}

void Menu::getCourseMenu()
{
    cout << "=========COURSE MENU=========" << endl;
}

void Menu::getTeacherMenu()
{
    cout << "=========TEACHER MENU=========" << endl;
    cout << "1. View courses I teach" << endl;
    cout << "2. Teach new course" << endl;
    cout << "3. View profile" << endl;
    cout << "0. Logout" << endl;
    cout << "What would you like to do: ";
}

void Menu::getRegistrationMenu(string role)
{
    cout << "=========REGISTRATION=========" << endl;
}