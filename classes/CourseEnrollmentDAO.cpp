#include "../headers/CourseEnrollmentDAO.h"

vector<CourseEnrollment> CourseEnrollmentDAO::retrieveAllEnrollmentRecords()
{
    vector<CourseEnrollment> enrollments;
    ifstream enrollment_records(fileName);

    string record;

    while (getline(enrollment_records, record))
    {
        vector<string> properties = RecordManager::splitRecord(record, ',');

        CourseEnrollment e;

        if (properties.size() == 3)
        {
            e.setEnrollmentID(stoi(properties.at(0)));
            e.setCourseID(properties.at(1));
            e.setStudentID(properties.at(2));
            enrollments.push_back(e);
        }
    }
    enrollment_records.close();
    return enrollments;
}

vector<CourseEnrollment> CourseEnrollmentDAO::retrieveCoursesEnrolledByStudent(string studentID)
{
    vector<CourseEnrollment> enrollments = retrieveAllEnrollmentRecords();
    vector<CourseEnrollment> enrollmentsOfStudent;

    for (CourseEnrollment e : enrollments)
    {
        if (e.getStudentID() == studentID)
        {
            enrollmentsOfStudent.push_back(e);
        }
    }
    return enrollmentsOfStudent;
}

vector<CourseEnrollment> CourseEnrollmentDAO::retrieveStudentsEnrolledInCourse(string courseID)
{
    vector<CourseEnrollment> enrollments = retrieveAllEnrollmentRecords();
    vector<CourseEnrollment> studentsEnrolled;

    for (CourseEnrollment e : enrollments)
    {
        if (e.getCourseID() == courseID)
        {
            studentsEnrolled.push_back(e);
        }
    }
    return studentsEnrolled;
}