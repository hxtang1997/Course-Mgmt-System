#include "Student.h"

Student() {}

Student(string id, string name, char gender, int phone)
{
    this->id = id;
    this->name = name;
    this->gender = gender;
    this->phone = phone;
}

string getName()
{
    return this->name;
}

string getID()
{
    return this->id;
}

char getGender()
{
    return this->gender;
}

int getPhone()
{
    return this->phone;
}

void setName(string name)
{
    this->name = name;
}

void setID(string id)
{
    this->id = id;
}

void setGender(char gender)
{
    this->gender = gender;
}

void setPhone(int phone)
{
    this->phone = phone;
}

string toString() {
    string toReturn = this->id + "," + this->name + "," + this->gender + ",";
    toReturn += to_string(this->phone);
    return toReturn;
}