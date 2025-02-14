#include "entry.h"

using namespace std;

entry::entry(const string& title, const string& user, const string& pass)
    : titleName(title), username(user), password(pass){}

string entry::getTitleName() const { return titleName; }
string entry::getUsername() const { return username; }
string entry::getPassword() const { return password; }

void entry::setTitleName(const string& title) { titleName = title; }
void entry::setUsername(const string& user) { username = user; }
void entry::setPassword(const string& pass) { password = pass; }
