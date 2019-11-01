#include "../headers/CourseDAO.h"

vector<Course> CourseDAO::retrieveCourseRecords()
{
    vector<Course> courses;
    ifstream course_records(fileName);

    string record;

    while (getline(course_records, record))
    {
        vector<string> properties = RecordManager::splitRecord(record, ',');

        Course c;

        if (properties.size() == 3)
        {
            c.setID(properties.at(0));
            c.setName(properties.at(1));
            c.setTeacher(properties.at(2));
            courses.push_back(c);
        }
    }
    course_records.close();
    return courses;
}

void CourseDAO::insertCourseRecord(Course c)
{
    vector<Course> courses;
    courses = retrieveCourseRecords();
    int id;
    id = courses.size() + 1;
    c.setID(to_string(id));
    ofstream records;
    records.open(fileName);
    records << to_string(id) << "," << c.getName() << "," << c.getTeacher() << endl;
    records.close();
}

Course CourseDAO::retrieveCourse(string id)
{
    vector<Course> course_records = retrieveCourseRecords();
    for (Course c : course_records)
    {
        if (c.getID() == id)
        {
            return c;
        }
    }
    throw "Course does not exist!";
}

void CourseDAO::updateCourseRecord(Course course)
{
    vector<Course> courses = retrieveCourseRecords();

    for (int i = 0; i <= courses.size(); i++)
    {
        Course c = courses.at(i);
        if (c.getID() == course.getID())
        {
            if (c.getName() != course.getName())
            {
                c.setName(course.getName());
            }

            if (c.getTeacher() != course.getTeacher())
            {
                c.setTeacher(course.getTeacher());
            }

            courses.at(i) = c;
            break;
        }
    }

    fstream course_records(fileName);

    for (Course c : courses)
    {
        course_records << c.toString() << endl;
    }
    course_records.close();
}

void CourseDAO::deleteCourseRecord(string id)
{
    vector<Course> courses = retrieveCourseRecords();

    string tempFileName = "temp.txt";
    ofstream temp;
    temp.open(tempFileName);

    for (Course c : courses)
    {
        if (c.getID() != id)
        {
            temp << c.toString() << endl;
        }
    }

    temp.close();
    remove(fileName.c_str());
    rename(tempFileName.c_str(), fileName.c_str());
}

vector<Course> CourseDAO::retrieveCoursesByTeacher(string teacher)
{
    vector<Course> courses = retrieveCourseRecords();
    vector<Course> courseByTeacher;

    for (Course c : courses)
    {
        if (c.getTeacher() == teacher)
        {
            courseByTeacher.push_back(c);
        }
    }
    return courseByTeacher;
}