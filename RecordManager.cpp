#include "RecordManager.h"
#include <exception>
#include <sstream>
using namespace std;

vector<string> RecordManager::splitRecord(const string record, char delimiter){
    vector<string> result;
    stringstream ss (record);
    string prop;

    while(getline(ss, prop, delimiter)){
        result.push_back(prop);
    }
    return result;
}