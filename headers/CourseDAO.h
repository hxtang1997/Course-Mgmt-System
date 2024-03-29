#ifndef COURSEDAO_H
#define COURSEDAO_H

#include <string>
#include <vector>
#include "Course.h"
#include "RecordManager.h"
#include <fstream>
#include <ostream>
using namespace std;

class CourseDAO {
    private:
    string fileName = "./courses.txt";

    public:
    vector<Course> retrieveCourseRecords();

    void insertCourseRecord(Course c);

    Course retrieveCourse(string id);

    void updateCourseRecord(Course course);

    void deleteCourseRecord(string id);

    vector<Course> retrieveCoursesByTeacher(string teacher);
};

#endif