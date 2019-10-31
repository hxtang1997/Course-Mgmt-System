#include "../headers/Student.h"

Student::Student() {}

Student::Student(string id, string name)
{
    this->id = id;
    this->name = name;
}

string Student::getName()
{
    return this->name;
}

string Student::getID()
{
    return this->id;
}

void Student::setName(string name)
{
    this->name = name;
}

void Student::setID(string id)
{
    this->id = id;
}


string Student::toString() {
    string toReturn = this->id + "," + this->name;
    return toReturn;
}