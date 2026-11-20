#include <iostream> 
#include "./userMenu.h"
#include "../Auth/auth.h"
#include "../Tiket/tiket.h"
#include "../input.h"
#include <cstdlib>
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
        pilihan = readInt("Pilih menu: ");


        switch (pilihan) {
            case 1: 
                cout << "Buat ticket untuk user (ID: " << userId << ")\n";
                    menuTicketUser(userId); 
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