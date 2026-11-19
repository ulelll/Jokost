#include <iostream> 
#include "userMenu.h"
#include "auth.h"
using namespace std; 

void userMenu(int userId) {
    int pilihan;
    do {
        cout << "============================\n";
        cout << "  JOKOST MANAGEMENT SYSTEM \n";
        cout << "============================\n";
        cout << "======== USER MENU ========\n";
        cout << "1. Buat Tiket\n";
        cout << "2. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: 
                cout << "Buat ticket untuk user (ID: " << userId << ")\n"; //todo: buat menu bikin tiket
                break;
            case 2:
                system("cls");
                logout();
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        } 
    } while (pilihan != 2); 
   


}