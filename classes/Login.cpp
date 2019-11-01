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
	}catch(const char* e){
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

string Login::login(string id) {
    try{
	    verifyStudent(id);
	    return "s";
    }catch(...){
    	try{
    		verifyTeacher(id);
    		return "t";
    	}catch(...){
    		cout << "ID does not exist. Please sign up." << endl;
	    	return "-1";
    	}
    }
}

