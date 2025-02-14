#include "StorageHandler.h"
#include <fstream>
#include <iostream>

using namespace std;

void StorageHandler::saveToFile(const string& filePath, const vector<entry>& entries){
    json j;

    //converting to json
    for(const auto &e : entries){
        json item;
        item["title"]    = e.getTitleName();
        item["username"] = e.getUsername();
        item["password"] = e.getPassword();

        j.push_back(item);
    }

    ofstream out(filePath);
    if(!out.is_open()){
        cerr << "Unable to open file.\n";
        return;
    }

    //write json
    out << j.dump(4);
    out.close();
}

vector<entry> StorageHandler::loadFile(const string &filePath){
    vector<entry> entries;
    ifstream in(filePath);

    //if file doesn't exist, create one
    if(!in.is_open()){
        //creating an empty file
        ofstream out(filePath);
        out << "[]";
        out.close();

        return entries;
    }

    json j;
    in >> j;

    //parse
    for(auto& element : j){
        string title = element.value("title", "");
        string username = element.value("username", "");
        string password = element.value("password", "");
        entries.push_back(entry(title, username, password));
    }

    return entries;
}


