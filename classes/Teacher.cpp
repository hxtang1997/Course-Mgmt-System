#include "../headers/Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(string id, string name) {
    this->id = id;
    this->name = name;
}

string Teacher::getName() {
    return this->name;
}

string Teacher::getID() {
    return this->id;
}

void Teacher::setName(string name) {
    this->name = name;
}

void Teacher::setID(string id) {
    this->id = id;
}

string Teacher::toString() {
    string toReturn = this->id + "," + this->name;
    return toReturn;
}