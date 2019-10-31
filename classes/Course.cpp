#include "../headers/Course.h"

Course::Course() {}

Course::Course(string id, string name, string teacher_id) {
    course_id = id;
    course_name = name;
    this->teacher_id = teacher_id;
}

string Course::getName() {
    return this->course_name;
}

string Course::getID() {
    return this->course_id;
}

string Course::getTeacher() {
    return this->teacher_id;
}

void Course::setName(string name) {
    course_name = name;
}

void Course::setID(string id) {
    course_id = id;
}

void Course::setTeacher(string id) {
    teacher_id = id;
}

string Course::toString() {
    return course_id + "," + course_name + "," + teacher_id;
}