#include "../headers/TeacherDAO.h"

void TeacherDAO::insertTeacherRecord(Teacher t)
{
    ofstream records;
    records.open(fileName);
    records << t.getID() << "," << t.getName() << "," << t.getGender() << "," << t.getPhone() << endl;
    records.close();
}

vector<Teacher> TeacherDAO::retrieveTeacherRecords()
{
    vector<Teacher> teachers;
    fstream teacher_records(fileName);

    string record;

    while (getline(teacher_records, record))
    {
        vector<string> properties = RecordManager::splitRecord(record, ',');

        Teacher t;

        if (properties.size() == 4)
        {
            t.setID(properties.at(0));
            t.setName(properties.at(1));
            t.setGender(properties.at(2).c_str()[0]);
            t.setPhone(stoi(properties.at(3)));
            teachers.push_back(t);
        }
    }
    teacher_records.close();
    return teachers;
}

Teacher TeacherDAO::retrieveTeacher(string id)
{
    vector<Teacher> teacher_records = retrieveTeacherRecords();
    for (Teacher t : teacher_records)
    {
        if (t.getID() == id)
        {
            return t;
        }
    }
    throw "Teacher does not exist!";
}

void TeacherDAO::updateTeacherRecord(Teacher teacher)
{
    vector<Teacher> teachers = retrieveTeacherRecords();

    for (int i = 0; i <= teachers.size(); i++)
    {
        Teacher t = teachers.at(i);
        if (t.getID() == teacher.getID())
        {
            if (t.getName() != teacher.getName())
            {
                t.setName(teacher.getName());
            }

            if (t.getGender() != teacher.getGender())
            {
                t.setGender(teacher.getGender());
            }

            if (t.getPhone() != teacher.getPhone())
            {
                t.setPhone(teacher.getPhone());
            }
            teachers.at(i) = t;
            break;
        }
    }

    fstream teacher_records(fileName);

    for (Teacher t : teachers)
    {
        teacher_records << t.toString() << endl;
    }
    teacher_records.close();
}

void TeacherDAO::deleteTeacherRecord(string id)
{
    vector<Teacher> teachers = retrieveTeacherRecords();

    string tempFileName = "temp.txt";
    ofstream temp;
    temp.open(tempFileName);

    for (Teacher t : teachers)
    {
        if (t.getID() != id)
        {
            temp << t.toString() << endl;
        }
    }

    temp.close();
    remove(fileName.c_str());
    rename(tempFileName.c_str(), fileName.c_str());
}