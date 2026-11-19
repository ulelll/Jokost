#include <iostream>
#include <vector>
#include "menu.h"
#include "auth.h"
#include "user.h"
#include "adminMenu.h"
#include "userMenu.h"

using namespace std;

int main() {

    vector<User> daftarUser = buatDataUser();

    int pilihan;

    do {
        pilihan = mainMenu();
        if (pilihan == 1) {
            int hasil = login(daftarUser);
            if (hasil == LOGIN_ADMIN) {
                system("cls");
                int pilihanAdmin;
                do {
                    pilihanAdmin = adminMenu();
                    switch (pilihanAdmin) {
                        case 1:
                            cout << "Masuk ke menu manajemen penghuni.\n";
                            //TODO: tampilkan daftar penghuni
                            break;
                        case 2:
                            cout << "Masuk ke menu pembayaran kost.\n";
                            //TODO: pembayaran kost
                            break;
                        case 3:
                            cout << "Masuk ke menu ticket keluhan.\n";
                            //TODO: ticket keluhan
                            break;
                        case 4:
                            cout << "Masuk ke menu laporan pembayaran.\n";
                            //TODO: laporan pembayaran
                            break;
                        case 5:
                            system("cls"); 
                            logout();
                            break;
                        default:
                            cout << "Pilihan tidak valid!\n";
                    }
                } while (pilihanAdmin != 5);
            }
            else if (hasil != LOGIN_FAILED) {
                system("cls");
                userMenu(hasil); // hasil = id yg login

            }
        }
        else if (pilihan == 0) {
            cout << "Program selesai.\n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);
    return 0;
}