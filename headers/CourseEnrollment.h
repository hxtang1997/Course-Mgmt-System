#ifndef COURSEENROLLMENT_H
#define COURSEENROLLMENT_H

#include <string>
using namespace std;

class CourseEnrollment {
    private:
    int course_enrollment_id;
    string course_id;
    string student_id;

    public:
    CourseEnrollment();

    CourseEnrollment(int id, string course, string student);

    int getEnrollmentID();

    string getCourseID();

    string getStudentID();

    void setEnrollmentID(int id);

    void setCourseID(string id);

    void setStudentID(string id);

    string toString();
};

#endif