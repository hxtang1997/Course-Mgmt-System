#include "../headers/Menu.h"
#include "../headers/Login.h"

int main(int argc, char**argv){
    bool run = true;
    int next;
    while (run != false){
        Menu::getWelcomeMenu();
        cin >> next;
        if (next == 1){
        	Menu::getLoginMenu();
    	    Login l;
    	    string userid;
    		userid =  l.login();
    		if (userid == "-1"){
    			continue;
    		}
        }else if(next == 0){
        	run = false;
        }
    }
    exit(0);
    return 0;
}