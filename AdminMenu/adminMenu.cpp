#include <iostream> 
#include "adminMenu.h"
using namespace std; 

int adminMenu(){

int pilihan; 

    cout << "============================\n";   
    cout << "  JOKOST MANAGEMENT SYSTEM \n";
    cout << "============================\n";
    cout << "======== ADMIN MENU ========\n";
    cout << "1. Manajemen Penghuni \n"; //to do: tampilkan list penghuni aja
    cout << "2. Pembayaran Kost\n"; //to do: by id yh. alur -> masukin id user -> masukin bulan (atau ama tanggal juga) -> masukin nominal -> masukin status (lunas atau belum) -> masukin keterangan (opsional)
    cout << "3. Ticket Keluhan\n";
    cout << "4. Laporan Pembayaran\n";
    cout << "5. Manajemen Kamar\n";
    cout << "6. Logout\n";
    cout << "Pilih menu: ";
    cin >> pilihan;

    return pilihan;
    
}