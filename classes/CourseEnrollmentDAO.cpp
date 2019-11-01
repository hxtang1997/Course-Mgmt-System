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

        if (properties.size() == 2)
        {
            e.setCourseID(properties.at(0));
            e.setStudentID(properties.at(1));
            enrollments.push_back(e);
        }
    }
    enrollment_records.close();
    return enrollments;
}

void CourseEnrollmentDAO::deleteCourseEnrollmentRecord(string uid, string cid)
{
    vector<CourseEnrollment> vce = retrieveAllEnrollmentRecords();

    string tempFileName = "temp.txt";
    ofstream temp;
    temp.open(tempFileName);

    for (CourseEnrollment ce : vce)
    {
        if (ce.getCourseID() != cid && ce.getStudentID() != uid)
        {
            temp << ce.toString() << endl;
        }
    }

    temp.close();
    remove(fileName.c_str());
    rename(tempFileName.c_str(), fileName.c_str());
}

void CourseEnrollmentDAO::insertCourseEnrollmentRecord(CourseEnrollment ce)
{
    //vector<CourseEnrollment> vce;
    //vce = retrieveAllEnrollmentRecords();
    //int id;
    //id = vce.size() + 1;
    //vce.setID(to_string(id));
    ofstream records;
    records.open(fileName);
    records << ce.getCourseID() << "," << ce.getStudentID() << endl;
    records.close();
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