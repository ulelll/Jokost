#ifndef ADMIN_H 
#define ADMIN_H 

#include <string>
#include <vector>
using namespace std;

class Admin {
    private: 
    string username; 
    string password; 

    public: 
    Admin(const string& username, const string& password); 
    bool login(const string& u, const string& p) const;

}; 


#endif