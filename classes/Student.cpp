#include "../headers/Student.h"

Student::Student() {}

Student::Student(string id, string name)
{
    Student::id = id;
    Student::name = name;
}

string Student::getName()
{
    return Student::name;
}

string Student::getID()
{
    return Student::id;
}

void Student::setName(string name)
{
    Student::name = name;
}

void Student::setID(string id)
{
    Student::id = id;
}


string Student::toString() {
    string toReturn = Student::id + "," + Student::name;
    return toReturn;
}