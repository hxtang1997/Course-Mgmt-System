#include "../headers/Menu.h"
#include "../headers/Login.h"
#include "../headers/Register.h"
#include "../headers/StudentDAO.h"
#include "../headers/Student.h"
#include "../headers/Course.h"
#include "../headers/CourseDAO.h"
#include "../headers/TeacherDAO.h"
#include "../headers/Teacher.h"
#include "../headers/CourseEnrollmentDAO.h"
#include "../headers/CourseEnrollment.h"


int main(int argc, char**argv){
    bool run = true;
    string next;
    while (run != false){
        Menu::getWelcomeMenu();
        cin >> next;
        if (next == "1"){
        	Menu::getLoginMenu();
        	cout << "ID: ";
		    string uid;
		    cin >> uid;
    	    Login l;
    	    string user;
    		user =  l.login(uid);
    		if (user == "-1"){
    			continue;
    		}else{
    			string next2;
    			bool loggedin = true;
    			CourseDAO cd;
    			while (loggedin){
	    			if (user == "s"){
	    				Menu::getStudentMenu();
	    				cin >> next2;
	    				if (next2 == "0"){
	    					loggedin = false;
	    				}else if (next2 == "1"){
	    					vector<Course> courses;
	    					courses = cd.retrieveCourseRecords();
	    					cout << "Course ID | Course Name" << endl;
	    					for (Course c : courses){
	    						cout << c.getID()  << " " << c.getName() << endl;
	    					}
	    				}else if (next2 == "2"){
	    					cout << "Enrollment of course: " << endl;
						    cout << "Course ID: ";
						    string cid;
						    cin >> cid;
						    try{
						    	Course c;
						    	CourseDAO cd;
						    	c =  cd.retrieveCourse(cid);
							    CourseEnrollment newCE(cid, uid);
							    CourseEnrollmentDAO  ceD;
							    ceD.insertCourseEnrollmentRecord(newCE);
							    cout << "Successfully enrolled into " << c.getName() << endl;
						    }catch(...){
						    	cout << "Invalid course id" << endl;
						    	continue;
						    }
	    				}else if (next2 == "3"){
	    					vector<CourseEnrollment> vce;
	    					CourseEnrollmentDAO cedao;
	    					vce = cedao.retrieveCoursesEnrolledByStudent(uid);
	    					cout << "You are currently enrolled in the following courses" << endl;
	    					cout << "Course ID | Course Name" << endl;
	    					for (CourseEnrollment ce : vce){
	    						CourseDAO cd;
	    						Course c = cd.retrieveCourse(ce.getCourseID());
	    						cout << c.getID()  << " " << c.getName() << endl;
	    					}

	    				}else if (next2 == "4"){
	    					//Withdraw  from course
	    					cout << "Withdrawal from Course" << endl;
						    cout << "Course ID: ";
						    string cid;
						    cin >> cid;
						    try{
						    	Course c;
						    	CourseDAO cd;
						    	c =  cd.retrieveCourse(cid);
							    CourseEnrollment newCE(cid, uid);
							    CourseEnrollmentDAO  ceD;
							    vector<CourseEnrollment> vce;
							    vce = ceD.retrieveCoursesEnrolledByStudent(uid);
							    bool found = false;
							    for (CourseEnrollment e : vce)
							    {
							        if (e.getCourseID() == cid)
							        {
							            found = true;
							        }
							    }
							    if (!found){
							    	cout << "You are not enrolled in this course" << endl;
							    	continue;
							    }else{
							    	ceD.deleteCourseEnrollmentRecord(uid, cid);
							    }
							    cout << "Successfully withdrawn from " << c.getName() << endl;
						    }catch(...){
						    	cout << "Invalid course id" << endl;
						    	continue;
						    }
	    					
	    				}else if (next2 == "5"){
	    					StudentDAO sd;
	    					Student s;
	    					s = sd.retrieveStudent(uid);
	    					cout << "Name: "  << s.getName() << endl;
	    					cout << "ID: " << s.getID() << endl;

	    				}
	    			}else if(user == "t"){
	    				Menu::getTeacherMenu();
	    				cin >> next2;
	    				if (next2 == "0"){
	    					loggedin = false;
	    				}else if (next2 == "1"){
	    					vector<Course> courses;
	    					courses = cd.retrieveCoursesByTeacher(uid);
	    					cout << "You are teaching the following courses:"  << endl;
	    					cout << "Course ID | Course Name" << endl;
	    					for (Course c : courses){
	    						cout << c.getID()  << " " << c.getName() << endl;
	    					}
	    				}else if (next2 == "2"){
	    					cout << "New Course name: ";
						    string cname;
							cin.ignore();
						    getline(cin, cname);
						    Course newCourse(cname, uid);
						    cd.insertCourseRecord(newCourse);

	    				}else if (next2 == "3"){
	    					//Remove  course teacher teach
	    					cout << "Remove Course I teach" << endl;
						    cout << "Course ID: ";
						    string cid;
						    cin >> cid;
						    try{
						    	Course d;
								CourseDAO cd;
								d =  cd.retrieveCourse(cid);
						    	vector<Course> courses;
	    						courses = cd.retrieveCoursesByTeacher(uid);
	    						bool found = false;
	    						for (Course c : courses){
		    						if (c.getTeacher() == uid){
		    							found = true;
		    						}
		    					}
		    					if (!found){
		    						cout << "You are not teaching this course" << endl;
		    						continue;
		    					}else{
		    						cd.deleteCourseRecord(cid);
		    					}
	    					}catch(...){
	    						cout << "Invalid course id" << endl;
	    					}

	    				}else if (next2 == "4"){
	    					//View class list
	    					vector<Course> courses;
	    					courses = cd.retrieveCoursesByTeacher(uid);
	    					cout << "Class List"  << endl;
	    					for (Course c : courses){
	    						cout << "Course ID | Course Name " << endl;
	    						cout << c.getID()  << " " << c.getName() << endl;
	    						cout << "Student Enrolled (ID,Name): " << endl;
	    						CourseEnrollmentDAO ced;
	    						vector<CourseEnrollment> vce = ced.retrieveStudentsEnrolledInCourse(c.getID());
	    						for (CourseEnrollment ce : vce){
	    							StudentDAO sd;
	    							Student s = sd.retrieveStudent(ce.getStudentID());
	    							cout << s.toString() << endl;
	    						}
	    					}

	    				}else if (next2 == "5"){
	    					TeacherDAO td;
	    					Teacher t;
	    					t = td.retrieveTeacher(uid);
	    					cout << "Name: "  << t.getName() << endl;
	    					cout << "ID: " << t.getID() << endl;
	    				}else{
	    					continue;
	    				}
	    			}
    			}
    		}
        }else if(next == "2" || next == "3"){
        	Menu::getRegistrationMenu(next);
        	Register r;
        	r.Registration(next);
        }
        else if(next == "0"){
        	exit(0);
        }
    }
    return 0;
}