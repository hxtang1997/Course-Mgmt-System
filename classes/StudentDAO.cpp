#include "../headers/StudentDAO.h"

void StudentDAO::insertStudentRecord(Student s)
{
    ofstream records;
    records.open(fileName);
    records << s.getID() << "," << s.getName() << endl;
    records.close();
}

vector<Student> StudentDAO::retrieveStudentRecords()
{
    vector<Student> students;
    fstream student_records(fileName);

    string record;

    while (getline(student_records, record))
    {
        vector<string> properties = RecordManager::splitRecord(record, ',');

        Student s;

        if (properties.size() == 4)
        {
            s.setID(properties.at(0));
            s.setName(properties.at(1));
            students.push_back(s);
        }
    }
    student_records.close();
    return students;
}

Student StudentDAO::retrieveStudent(string id)
{
    vector<Student> student_records = retrieveStudentRecords();
    for (Student s : student_records)
    {
        if (s.getID() == id)
        {
            return s;
        }
    }
    throw "Student does not exist!";
}

void StudentDAO::updateStudentRecord(Student student)
{
    vector<Student> students = retrieveStudentRecords();

    for (int i = 0; i <= students.size(); i++)
    {
        Student s = students.at(i);
        if (s.getID() == student.getID())
        {
            if (s.getName() != student.getName())
            {
                s.setName(student.getName());
            }

            students.at(i) = s;
            break;
        }
    }

    fstream student_records(fileName);

    for (Student s : students)
    {
        student_records << s.toString() << endl;
    }
    student_records.close();
}

void StudentDAO::deleteStudentRecord(string id)
{
    vector<Student> students = retrieveStudentRecords();

    string tempFileName = "temp.txt";
    ofstream temp;
    temp.open(tempFileName);

    for (Student s : students)
    {
        if (s.getID() != id)
        {
            temp << s.toString() << endl;
        }
    }

    temp.close();
    remove(fileName.c_str());
    rename(tempFileName.c_str(), fileName.c_str());
}