#include "../headers/CourseEnrollment.h"

CourseEnrollment::CourseEnrollment() {}

CourseEnrollment::CourseEnrollment(int id, string course, string student)
{
    course_enrollment_id = id;
    course_id = course;
    student_id = student;
}

int CourseEnrollment::getEnrollmentID()
{
    return course_enrollment_id;
}

string CourseEnrollment::getCourseID()
{
    return course_id;
}

string CourseEnrollment::getStudentID()
{
    return student_id;
}

void CourseEnrollment::setEnrollmentID(int id)
{
    course_enrollment_id = id;
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
    string toReturn = to_string(this->course_enrollment_id) + "," + this->course_id + "," + this->student_id;
    return toReturn;
}