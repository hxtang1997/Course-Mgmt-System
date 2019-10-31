#ifndef STUDENTDAO_H
#define STUDENTDAO_H

#include <string>
#include <vector>
#include "Student.h"
#include "RecordManager.h"
#include <fstream>
#include <ostream>
using namespace std;

class StudentDAO {
    private:
    string fileName = "students.txt";

    public:
    void insertStudentRecord(Student s);

    vector<Student> retrieveStudentRecords();

    Student retrieveStudent(string id);

    void updateStudentRecord(Student student);

    void deleteStudentRecord(string id);
};

#endif