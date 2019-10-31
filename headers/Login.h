#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <iostream>
#include "Student.h"
#include "Teacher.h"
using namespace std;

class Login{
public:
    Student verifyStudent(string id);

    Teacher verifyTeacher(string id);

    string login();
};

#endif