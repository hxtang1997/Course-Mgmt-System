#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course {
    private:
    string course_id;
    string course_name;
    string teacher_id;

    public:
    Course();

    Course(string id, string name, string teacher_id);

    Course(string name, string teacher_id);

    string getName();

    string getID();

    string getTeacher();

    void setName(string name);

    void setID(string id);

    void setTeacher(string id);

    string toString();
};

#endif