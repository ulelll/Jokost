#include <iostream>
#include <string> 
#include "auth.h" 

using namespace std; 

const string ADMIN_USERNAME = "admin";
const string ADMIN_PASSWORD = "admin123"; 

int login(const vector<User>& daftarUser){

    string username; 
    string password; 

    cout << "\n============================\n";
    cout << "       LOGIN JOKOST\n";
    cout << "============================\n";
    cout << "Username : ";
    cin >> username;

    cout << "Password : ";
    cin >> password;

    //validasi admin 
    if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD){
        return LOGIN_ADMIN; 
    }

    //validasi user biasa 
    for (size_t i = 0; i < daftarUser.size(); i++){
        if (daftarUser[i].getUsername() == username && daftarUser[i].checkPassword(password)){
            return daftarUser[i].getId(); 
        }
    }

    // kalau salah 
    cout << "\nUsername atau password salah!\n"; 
    return LOGIN_FAILED; 
}

//logout 
void logout() {
        cout << "\n============================\n";
        cout << "       Logout berhasil.   \n";
        cout << "============================\n";
}





