#include <iostream> 
#include "menu.h"
using namespace std; 


int main(){

    int pilihan; 

    pilihan = mainMenu(); 

    if (pilihan == 1){

        cout << "Menu login dipilih.\n"; 
    }
    else if (pilihan == 0){

        cout << "program selesai.\n";
    }
    else {
        cout << "Pilihan tidak valid!";
    }

    return 0; 
}