#include "../headers/Register.h"
#include "../headers/Student.h"
#include "../headers/Teacher.h"
#include "../headers/StudentDAO.h"
#include "../headers/TeacherDAO.h"



void Register::Registration(string role) {
    cout << "Name: ";
    string name;
	cin.ignore();
    getline(cin, name);
    string id;
    if(role == "2"){
    	cout << "Student ID: ";
    	cin >> id;
    	Student s(id, name);
    	StudentDAO sd;
    	sd.insertStudentRecord(s);
    }else{
    	cout << "Teacher ID: ";
    	cin >> id;
    	Teacher t(id, name);
    	TeacherDAO td;
    	td.insertTeacherRecord(t);
    }
    cout << "Registration successful. Please login." << endl;

}