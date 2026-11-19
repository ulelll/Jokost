#include <iostream> 
#include <vector> 
#include "menu.h"
#include "auth.h"
#include "user.h"

using namespace std; 


int main(){

    vector<User> daftarUser = buatDataUser(); 

    int pilihan; 
    do {
        pilihan = mainMenu(); 

        if (pilihan == 1){
           int hasil = login(daftarUser);
              if (hasil == LOGIN_ADMIN){
                     cout << "\nLogin berhasil sebagai Admin.\n"; // ADMIN MENU blm ada 
              } 
              else if (hasil != LOGIN_FAILED){
                  cout << "\nLogin berhasil sebagai penghuni (ID: " << hasil << ").\n"; // USER MENU blm ada
              }
        }
        else if (pilihan == 0){
            cout << "program selesai.\n";
        }
        else {
            cout << "Pilihan tidak valid!";
        }
    } while (pilihan != 0);    

    return 0; 
}