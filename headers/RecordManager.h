#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include <string>
#include <vector>
using namespace std;

class RecordManager {
    public:
        static vector<string> splitRecord(const string record, char delimiter);
};

#endif