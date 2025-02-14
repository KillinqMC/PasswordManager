#ifndef MANAGER_H
#define MANAGER_H

#include "entry.h"
#include <vector>

using namespace std;

class manager {
private:
    vector<entry> entries;
public:
    void addEntry(const entry& e);
    void deleteEntry(const string& titleName);
    entry* searchEntry(const string& entry);
    const vector<entry>& getAllEntries() const;
};

#endif
