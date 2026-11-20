#ifndef AUTH_H 
#define AUTH_H 
#include <vector> 
#include "../User/user.h"

const int LOGIN_FAILED = 0; 
const int LOGIN_ADMIN = -1; 

int login(const vector<User>& daftarUser); 

void logout();

#endif