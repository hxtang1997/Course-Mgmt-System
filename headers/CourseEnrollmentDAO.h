#ifndef COURSEENROLLMENTDAO_H
#define COURSEENROLLMENTDAO_H

#include <string>
#include <vector>
#include "CourseEnrollment.h"
#include "RecordManager.h"
#include <fstream>
#include <ostream>
using namespace std;

class CourseEnrollmentDAO{
    private:
    string fileName = "./course_enrollment.txt";

    public:
    vector<CourseEnrollment> retrieveAllEnrollmentRecords();

    void insertCourseEnrollmentRecord(CourseEnrollment ce);

    vector<CourseEnrollment> retrieveCoursesEnrolledByStudent(string studentID);

    vector<CourseEnrollment> retrieveStudentsEnrolledInCourse(string courseID);
};

#endif