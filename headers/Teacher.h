#ifndef TEACHER_H
#define TEACHER_H

#include <string>
using namespace std;

class Teacher {
    private:
    string id;
    string name;
    char gender;
    int phone;

    public:
    Teacher();

    Teacher(string id, string name, char gender, int phone);

    string getName();

    string getID();

    char getGender();

    int getPhone();

    void setName(string name);

    void setID(string id);

    void setGender(char gender);

    void setPhone(int phone);

    string toString();
};

#endif