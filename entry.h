#ifndef ENTRY_H
#define ENTRY_H

#include <string>

using namespace std;

class entry{
private:
    string titleName;
    string username;
    string password;
public:
    entry(const string& title, const string& user, const string& pass);

    string getTitleName() const;
    string getUsername() const;
    string getPassword() const;

    void setTitleName(const string& title);
    void setUsername(const string& user);
    void setPassword(const string& pass);

};

#endif
