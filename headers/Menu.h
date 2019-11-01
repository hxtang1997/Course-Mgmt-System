#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
using namespace std;

class Menu {
    public:
        static void getWelcomeMenu();

        static void getLoginMenu();

        static void getStudentMenu ();

        static void getCourseMenu ();

        static void getTeacherMenu ();

        static void getTeacherClassMenu ();

        static void getRegistrationMenu(string role);
};

#endif