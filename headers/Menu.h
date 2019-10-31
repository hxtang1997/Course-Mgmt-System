#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
using namespace std;

class Menu {
    public:
        static void getWelcomeMenu();

        static void getStudentMenu ();

        static void getCourseMenu ();

        static void getTeacherMenu ();

        static void getRegistrationMenu(string role);
};

#endif