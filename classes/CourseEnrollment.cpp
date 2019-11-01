#include "../headers/CourseEnrollment.h"

CourseEnrollment::CourseEnrollment() {}

CourseEnrollment::CourseEnrollment(string course, string student)
{
    course_id = course;
    student_id = student;
}

string CourseEnrollment::getCourseID()
{
    return course_id;
}

string CourseEnrollment::getStudentID()
{
    return student_id;
}

void CourseEnrollment::setCourseID(string id)
{
    course_id = id;
}

void CourseEnrollment::setStudentID(string id)
{
    student_id = id;
}

string CourseEnrollment::toString()
{
    string toReturn = this->course_id + "," + this->student_id;
    return toReturn;
}