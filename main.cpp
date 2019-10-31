#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <exception>
#include "RecordManager.h"
using namespace std;

struct CustomException : public std::exception
{
	const char * what () const throw ()
    {
    	return "Error occurred!";
    }
};

class Student {
    private:
    string id;
    string name;
    char gender;
    int phone;

    public:
    Student(){}
    Student(string id, string name, char gender, int phone){
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->phone = phone;
    }

    string getName(){
        return this->name;
    }

    string getID(){
        return this->id;
    }

    char getGender(){
        return this->gender;
    }

    int getPhone(){
        return this->phone;
    }

    void setName(string name){
        this->name = name;
    }

    void setID(string id){
        this->id = id;
    }

    void setGender(char gender){
        this->gender = gender;
    }

    void setPhone(int phone){
        this->phone = phone;
    }

    string toString(){
        string toReturn = this->id + "," + this->name + "," + this->gender + ",";
        toReturn += to_string(this->phone);
        return toReturn;
    }
};

class Teacher {
    private:
    string id;
    string name;
    char gender;
    int phone;

    public:
    Teacher(){}
    Teacher(string id, string name, char gender, int phone){
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->phone = phone;
    }

    string getName(){
        return this->name;
    }

    string getID(){
        return this->id;
    }

    char getGender(){
        return this->gender;
    }

    int getPhone(){
        return this->phone;
    }

    void setName(string name){
        this->name = name;
    }

    void setID(string id){
        this->id = id;
    }

    void setGender(char gender){
        this->gender = gender;
    }

    void setPhone(int phone){
        this->phone = phone;
    }

    string toString(){
        string toReturn = this->id + "," + this->name + "," + this->gender + ",";
        toReturn += to_string(this->phone);
        return toReturn;
    }
};

class Course {
    private:
    string course_id;
    string course_name;
    string teacher_id;

    public:
    Course(){}
    Course(string id, string name, string teacher_id){
        course_id = id;
        course_name = name;
        this->teacher_id = teacher_id;
    }

    string getName(){
        return this->course_name;
    }

    string getID(){
        return this->course_id;
    }

    string getTeacher(){
        return this->teacher_id;
    }

    void setName(string name){
        course_name = name;
    }

    void setID(string id){
        course_id = id;
    }

    void setTeacher(string id){
        teacher_id = id;
    }

    string toString(){
        return course_id + "," + course_name + "," + teacher_id;
    }
};

class CourseEnrollment {
    private:
    int course_enrollment_id;
    string course_id;
    string student_id;

    public:
    CourseEnrollment(){}

    CourseEnrollment(int id, string course, string student){
        course_enrollment_id = id;
        course_id = course;
        student_id = student;
    }

    int getEnrollmentID(){
        return course_enrollment_id;
    }

    string getCourseID(){
        return course_id;
    }

    string getStudentID(){
        return student_id;
    }

    void setEnrollmentID(int id){
        course_enrollment_id = id;
    }

    void setCourseID(string id){
        course_id = id;
    }

    void setStudentID(string id){
        student_id = id;
    }

    string toString(){
        string toReturn = to_string(this->course_enrollment_id) + "," + this->course_id + "," + this->student_id;
        return toReturn;
    }
};

class CourseEnrollmentDAO{
    private:
    string fileName = "course_enrollment.txt";

    public:
    vector<CourseEnrollment> retrieveAllEnrollmentRecords(){
        vector<CourseEnrollment> enrollments;
        fstream enrollment_records(fileName);

        string record;

        while(getline(enrollment_records, record)){
            vector<string> properties = RecordManager::splitRecord(record, ',');

            CourseEnrollment e;

            if(properties.size() == 3){
                e.setEnrollmentID(stoi(properties.at(0)));
                e.setCourseID(properties.at(1));
                e.setStudentID(properties.at(2));
                enrollments.push_back(e);
            }
        }
        enrollment_records.close();
        return enrollments;
    }

    vector<CourseEnrollment> retrieveCoursesEnrolledByStudent(string studentID){
        vector<CourseEnrollment> enrollments = retrieveAllEnrollmentRecords();
        vector<CourseEnrollment> enrollmentsOfStudent;

        for(CourseEnrollment e: enrollments){
            if(e.getStudentID() == studentID){
                enrollmentsOfStudent.push_back(e);
            }
        }
        return enrollmentsOfStudent;
    }

    vector<CourseEnrollment> retrieveStudentsEnrolledInCourse(string courseID){
        vector<CourseEnrollment> enrollments = retrieveAllEnrollmentRecords();
        vector<CourseEnrollment> studentsEnrolled;

        for(CourseEnrollment e: enrollments){
            if(e.getCourseID() == courseID){
                studentsEnrolled.push_back(e);
            }
        }
        return studentsEnrolled;
    }
};

class TeacherDAO {
    private:
    string fileName = "teachers.txt";

    public:
    void insertTeacherRecord(Teacher t){
        ofstream records;
        records.open(fileName);
        records << t.getID() << "," << t.getName() << "," << t.getGender() << "," << t.getPhone() << endl;
        records.close();
    }

    vector<Teacher> retrieveTeacherRecords(){
        vector<Teacher> teachers;
        fstream teacher_records(fileName);

        string record;

        while(getline(teacher_records, record)){
            vector<string> properties = RecordManager::splitRecord(record, ',');

            Teacher t;

            if(properties.size() == 4){
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

    Teacher retrieveTeacher(string id){
        vector<Teacher> teacher_records = retrieveTeacherRecords();
        for(Teacher t: teacher_records){
            if(t.getID() == id){
                return t;
            }
        }
        throw CustomException();
    }

    void updateTeacherRecord(Teacher teacher){
        vector<Teacher> teachers = retrieveTeacherRecords();

        for(int i = 0; i <= teachers.size(); i++){
            Teacher t = teachers.at(i);
            if(t.getID() == teacher.getID()){
                if(t.getName() != teacher.getName()){
                    t.setName(teacher.getName());
                }

                if(t.getGender() != teacher.getGender()){
                    t.setGender(teacher.getGender());
                }

                if(t.getPhone() != teacher.getPhone()){
                    t.setPhone(teacher.getPhone());
                }
                teachers.at(i) = t;
                break;
            }
        }

        fstream teacher_records(fileName);

        for(Teacher t: teachers){
            teacher_records << t.toString() << endl;
        }
        teacher_records.close();
    }

    void deleteTeacherRecord(string id){
        vector<Teacher> teachers = retrieveTeacherRecords();

        string tempFileName = "temp.txt";
        ofstream temp;
        temp.open(tempFileName);

        for(Teacher t: teachers){
            if(t.getID() != id){
                temp << t.toString() << endl;
            }
        }

        temp.close();
        remove(fileName.c_str());
        rename(tempFileName.c_str(), fileName.c_str());
    }
};

class CourseDAO {
    private:
    string fileName = "courses.txt";

    public:
    void insertCourseRecord(Course c){
        ofstream records;
        records.open(fileName);
        records << c.getID() << "," << c.getName() << endl;
        records.close();
    }

    vector<Course> retrieveCourseRecords(){
        vector<Course> courses;
        fstream course_records(fileName);

        string record;

        while(getline(course_records, record)){
            vector<string> properties = RecordManager::splitRecord(record, ',');

            Course c;

            if(properties.size() == 2){
                c.setID(properties.at(0));
                c.setName(properties.at(1));
                courses.push_back(c);
            }
        }
        course_records.close();
        return courses;
    }

    Course retrieveCourse(string id){
        vector<Course> course_records = retrieveCourseRecords();
        for(Course c: course_records){
            if(c.getID() == id){
                return c;
            }
        }
        throw CustomException();
    }

    void updateCourseRecord(Course course){
        vector<Course> courses = retrieveCourseRecords();

        for(int i = 0; i <= courses.size(); i++){
            Course c = courses.at(i);
            if(c.getID() == course.getID()){
                if(c.getName() != course.getName()){
                    c.setName(course.getName());
                }

                if(c.getTeacher() != course.getTeacher()){
                    c.setTeacher(course.getTeacher());
                }

                courses.at(i) = c;
                break;
            }
        }

        fstream course_records(fileName);

        for(Course c: courses){
            course_records << c.toString() << endl;
        }
        course_records.close();
    }

    void deleteCourseRecord(string id){
        vector<Course> courses = retrieveCourseRecords();

        string tempFileName = "temp.txt";
        ofstream temp;
        temp.open(tempFileName);

        for(Course c: courses){
            if(c.getID() != id){
                temp << c.toString() << endl;
            }
        }

        temp.close();
        remove(fileName.c_str());
        rename(tempFileName.c_str(), fileName.c_str());
    }

    vector<Course> retrieveCoursesByTeacher(string teacher){
        vector<Course> courses = retrieveCourseRecords();
        vector<Course> courseByTeacher;

        for(Course c: courses){
            if(c.getTeacher() == teacher){
                courseByTeacher.push_back(c);
            }
        }
        return courseByTeacher;
    }
};

class StudentDAO {
    private:
    string fileName = "students.txt";

    public:
    void insertStudentRecord(Student s){
        ofstream records;
        records.open(fileName);
        records << s.getID() << "," << s.getName() << "," << s.getGender() << "," << s.getPhone() << endl;
        records.close();
    }

    vector<Student> retrieveStudentRecords(){
        vector<Student> students;
        fstream student_records(fileName);

        string record;

        while(getline(student_records, record)){
            vector<string> properties = RecordManager::splitRecord(record, ',');

            Student s;

            if(properties.size() == 4){
                s.setID(properties.at(0));
                s.setName(properties.at(1));
                s.setGender(properties.at(2).c_str()[0]);
                s.setPhone(stoi(properties.at(3)));
                students.push_back(s);
            }
        }
        student_records.close();
        return students;
    }

    Student retrieveStudent(string id){
        vector<Student> student_records = retrieveStudentRecords();
        for(Student s: student_records){
            if(s.getID() == id){
                return s;
            }
        }
        throw CustomException();
    }

    void updateStudentRecord(Student student){
        vector<Student> students = retrieveStudentRecords();

        for(int i = 0; i <= students.size(); i++){
            Student s = students.at(i);
            if(s.getID() == student.getID()){
                if(s.getName() != student.getName()){
                    s.setName(student.getName());
                }

                if(s.getGender() != student.getGender()){
                    s.setGender(student.getGender());
                }

                if(s.getPhone() != student.getPhone()){
                    s.setPhone(student.getPhone());
                }
                students.at(i) = s;
                break;
            }
        }

        fstream student_records(fileName);

        for(Student s: students){
            student_records << s.toString() << endl;
        }
        student_records.close();
    }

    void deleteStudentRecord(string id){
        vector<Student> students = retrieveStudentRecords();

        string tempFileName = "temp.txt";
        ofstream temp;
        temp.open(tempFileName);

        for(Student s: students){
            if(s.getID() != id){
                temp << s.toString() << endl;
            }
        }

        temp.close();
        remove(fileName.c_str());
        rename(tempFileName.c_str(), fileName.c_str());
    }
};

class Register{
    public:
        void Registration(string role){
            cout << "Enter your name: " << endl;
            string name;
            cin >> name;
        }

};

class Menu {
    public:
        void getWelcomeMenu(){
            cout << "=========Course Management System=========" << endl;
            cout << "Welcome to the course management system" << endl;
            cout << "1. Login" << endl;
            cout << "2. Sign up (Student)" << endl;
            cout << "3. Sign up (Teacher)" << endl;
            cout << "0. Exit" << endl;
        }
        void getStudentMenu () {
            cout << "=========STUDENT MENU=========" << endl;
            cout << "1. View all courses" << endl;
            cout << "2. Enroll into a course (Please note the Course ID for enrollment)" << endl;
            cout << "3. View enrolled course" << endl;
            cout << "4. Withdraw from course" << endl;
            cout << "5. View profile" << endl;
            cout << "0. Exit" << endl;
        }

        void getCourseMenu (){
            cout << "=========COURSE MENU=========" << endl;
            //loop through course file
        }

        void getTeacherMenu () {
            cout << "=========TEACHER MENU=========" << endl;
            cout << "1. View courses I teach" << endl;
            cout << "2. Start a new course" << endl;
            cout << "3. View profile" << endl;
            cout << "0. Exit" << endl;
        }

        void getRegistrationMenu(string role){
            cout << "=========REGISTRATION=========" << endl;
            Register r;
            r.Registration(role);
        }
};

int main(int argc, char**argv){
    Menu menu;
    menu.getWelcomeMenu();
    exit(0);
    bool run = true;
    while (run != false){
        cout << "hi";
        run = false;
    }
    return 0;
}