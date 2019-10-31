#include "../headers/Login.h"
#include "../headers/Student.h"
#include "../headers/Teacher.h"
#include "../headers/StudentDAO.h"
#include "../headers/TeacherDAO.h"

Student Login::verifyStudent(string id){
	Student s;
	StudentDAO sd;
	try{
		sd.retrieveStudent(id);
	}catch(...){
		throw("-1");
	}
	return s;
}

Teacher Login::verifyTeacher(string id){
	Teacher t;
	TeacherDAO td;
	try{
		td.retrieveTeacher(id);
	}catch(...){
		throw("-1");
	}
	return t;
}

string Login::login() {
    cout << "ID: ";
    string id;
    cin >> id;
    try{
	    verifyStudent(id);
	    return id;
    }catch(...){
    	try{
    		verifyTeacher(id);
    		return id;
    	}catch(...){
    		cout << "ID does not exist. Please sign up." << endl;
	    	return "-1";
    	}
    }
}

