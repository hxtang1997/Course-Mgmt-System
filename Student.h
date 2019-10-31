#include <string>
#include <vector>
using namespace std;

class Student {
    private:
    string id;
    string name;
    char gender;
    int phone;

    public:
    Student();
    Student(string id, string name, char gender, int phone);

    string getName();

    string getID();

    char getGender();

    int getPhone();

    void setName(string name);

    void setID(string id);

    void setGender(char gender);

    void setPhone(int phone);

    string toString();
};