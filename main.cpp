#include <iostream>
#include <vector>
#include <string>
#include "Menu/menu.h"
#include "Auth/auth.h"
#include "User/user.h"
#include "AdminMenu/adminMenu.h"
#include "UserMenu/userMenu.h"
#include "Tiket/tiket.h"
#include "Kamar/kamar.h"
#include "Pembayaran/pembayaran.h"
#include "input.h"

using namespace std;

int main() {
    vector<User> daftarUser = buatDataUser();
    vector<Pembayaran> daftarPembayaran;

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
                        case 1: {
                            cout << "Masuk ke menu manajemen penghuni.\n";
                            if (daftarUser.empty()) {
                                cout << "Belum ada data penghuni.\n";
                            } else {
                                for (const auto& u : daftarUser) {
                                    u.tampil();
                                    cout << "------------------------\n";
                                }
                            }
                            break;
                        }
                        case 2: {
                            cout << "Masuk ke menu pembayaran kost.\n";
                            menuPembayaran(daftarPembayaran, daftarUser);
                            break;
                        }
                        case 3: {
                            cout << "Masuk ke menu ticket keluhan.\n";
                            menuTicketAdmin();
                            break;
                        }
                        case 4: {
                            cout << "Masuk ke menu laporan pembayaran.\n";
                            laporanPembayaran(daftarPembayaran, daftarUser);
                            break;
                        }
                        case 5: { 
                            cout << "============================\n";
                            cout << "Masuk ke menu manajemen kamar.\n";
                            vector<Kamar> daftarKamar = buatDataKamar(daftarUser);
                            menuManajemenKamar(daftarKamar, daftarUser);
                        break;
                        }
                        case 6:
                            system("cls");
                            logout();
                            break;
                        default:
                            cout << "Pilihan tidak valid!\n";
                    }
                } while (pilihanAdmin != 6);
            }
            else if (hasil != LOGIN_FAILED) {
                system("cls");
                userMenu(hasil); 
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