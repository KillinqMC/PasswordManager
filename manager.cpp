#include "manager.h"

using namespace std;

void manager::addEntry(const entry  & e){
    entries.push_back(e);
}

void manager::deleteEntry(const string& titleName){
    for(auto it = entries.begin(); it != entries.end(); ++it){
        if(it->getTitleName() == titleName){
            entries.erase(it);
            break;
        }
    }
}

entry* manager::searchEntry(const string& titleName){
    for(auto& e : entries){
        if(e.getTitleName() == titleName){
            return &e;
        }
    }
    return nullptr;
}

const vector<entry>& manager::getAllEntries() const{
    return entries;
}
