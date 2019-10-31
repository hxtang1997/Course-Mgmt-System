#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
    private:
    string id;
    string name;

    public:
    Student();
    Student(string id, string name);

    string getName();

    string getID();

    void setName(string name);

    void setID(string id);

    string toString();
};

#endif