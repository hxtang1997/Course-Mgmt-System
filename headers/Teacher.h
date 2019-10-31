#ifndef TEACHER_H
#define TEACHER_H

#include <string>
using namespace std;

class Teacher {
    private:
    string id;
    string name;

    public:
    Teacher();

    Teacher(string id, string name);

    string getName();

    string getID();

    void setName(string name);

    void setID(string id);

    string toString();
};

#endif