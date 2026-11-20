#include "./admin.h"
#include <iostream> 

using namespace std; 

Admin::Admin(const string& username, const string& password)
    : username(username), password(password) {}

bool Admin::login(const string& u, const string& p) const {
    return username == u && password == p;
} 