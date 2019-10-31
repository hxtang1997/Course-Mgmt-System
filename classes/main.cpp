#include "../headers/Menu.h"
#include "../headers/Login.h"
#include "../headers/Register.h"
#include "../headers/StudentDAO.h"
#include "../headers/Student.h"


int main(int argc, char**argv){
    bool run = true;
    string next;
    StudentDAO sd;
    Student s;
    s = sd.retrieveStudent("123");
    s.toString();
    while (run != false){
        Menu::getWelcomeMenu();
        cin >> next;
        if (next == "1"){
        	Menu::getLoginMenu();
    	    Login l;
    	    string userid;
    		userid =  l.login();
    		if (userid == "-1"){
    			continue;
    		}
        }else if(next == "2" || next == "3"){
        	Menu::getRegistrationMenu(next);
        	Register r;
        	r.Registration(next);
        }
        else if(next == "0"){
        	run = false;
        }
    }
    exit(0);
    return 0;
}