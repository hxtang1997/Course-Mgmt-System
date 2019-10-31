#include "../headers/Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(string id, string name, char gender, int phone) {
    this->id = id;
    this->name = name;
    this->gender = gender;
    this->phone = phone;
}

string Teacher::getName() {
    return this->name;
}

string Teacher::getID() {
    return this->id;
}

char Teacher::getGender() {
    return this->gender;
}

int Teacher::getPhone() {
    return this->phone;
}

void Teacher::setName(string name) {
    this->name = name;
}

void Teacher::setID(string id) {
    this->id = id;
}

void Teacher::setGender(char gender) {
    this->gender = gender;
}

void Teacher::setPhone(int phone) {
    this->phone = phone;
}

string Teacher::toString() {
    string toReturn = this->id + "," + this->name + "," + this->gender + ",";
    toReturn += to_string(this->phone);
    return toReturn;
}