#ifndef TEACHERDAO_H
#define TEACHERDAO_H

#include <string>
#include <vector>
#include "Teacher.h"
#include "RecordManager.h"
#include <fstream>
#include <ostream>
using namespace std;

class TeacherDAO {
    private:
    string fileName = "./teachers.txt";

    public:
    void insertTeacherRecord(Teacher t);

    vector<Teacher> retrieveTeacherRecords();

    Teacher retrieveTeacher(string id);

    void updateTeacherRecord(Teacher teacher);

    void deleteTeacherRecord(string id);
};

#endif