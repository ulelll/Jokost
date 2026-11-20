#include <iostream> 
#include "menu.h"
using namespace std;

int mainMenu(){

int pilihan; 

    cout << "============================\n";
    cout << "  JOKOST MANAGEMENT SYSTEM \n";
    cout << "============================\n";
    cout << "1. Login\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
    cin >> pilihan;

    return pilihan; 

}