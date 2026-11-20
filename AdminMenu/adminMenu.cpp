#include <iostream> 
#include "adminMenu.h"
#include "../input.h"
using namespace std; 

int adminMenu(){

int pilihan; 

    cout << "============================\n";   
    cout << "  JOKOST MANAGEMENT SYSTEM \n";
    cout << "============================\n";
    cout << "======== ADMIN MENU ========\n";
    cout << "1. Manajemen Penghuni \n"; 
    cout << "2. Pembayaran Kost\n";
    cout << "4. Laporan Pembayaran\n";
    cout << "5. Manajemen Kamar\n"; 
    cout << "6. Logout\n";
    cout << "Pilih menu: ";
    pilihan = readInt("Pilih menu: ");

    return pilihan;
    
}