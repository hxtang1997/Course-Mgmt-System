#include "../headers/Student.h"

Student::Student() {}

Student::Student(string id, string name, char gender, int phone)
{
    Student::id = id;
    Student::name = name;
    Student::gender = gender;
    Student::phone = phone;
}

string Student::getName()
{
    return Student::name;
}

string Student::getID()
{
    return Student::id;
}

char Student::getGender()
{
    return Student::gender;
}

int Student::getPhone()
{
    return Student::phone;
}

void Student::setName(string name)
{
    Student::name = name;
}

void Student::setID(string id)
{
    Student::id = id;
}

void Student::setGender(char gender)
{
    Student::gender = gender;
}

void Student::setPhone(int phone)
{
    Student::phone = phone;
}

string Student::toString() {
    string toReturn = Student::id + "," + Student::name + "," + Student::gender + ",";
    toReturn += to_string(Student::phone);
    return toReturn;
}