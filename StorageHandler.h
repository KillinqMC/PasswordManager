#ifndef STORAGE_HANDLER_H
#define STORAGE_HANDLER_H

#include <vector>
#include <string>
#include "entry.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class StorageHandler{
public:
    void saveToFile(const string &filePath, const vector<entry>& entries);
    vector<entry> loadFile(const string &filePath);
};



#endif
