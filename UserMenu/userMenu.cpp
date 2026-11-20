#include <iostream> 
#include "./userMenu.h"
#include "../Auth/auth.h"
#include "../Tiket/tiket.h"
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
                cout << "Buat ticket untuk user (ID: " << userId << ")\n";
                    menuTicketUser(); 
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