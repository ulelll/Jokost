#include <iostream>
#include <vector>
#include <string>
#include "Menu/menu.h"
#include "Auth/auth.h"
#include "User/user.h"
#include "AdminMenu/adminMenu.h"
#include "UserMenu/userMenu.h"
#include "Tiket/tiket.h"

using namespace std;

// Struct tambahan agar data pembayaran & keluhan bisa disimpan
struct Pembayaran {
    int id;
    int userId;
    string bulan;
    int nominal;
    bool lunas;
};

struct Keluhan {
    int id;
    int userId;
    string isi;
    string status; // "Menunggu", "Diproses", "Selesai"
};

int main() {
    vector<User> daftarUser = buatDataUser();
    vector<Pembayaran> daftarPembayaran;
    vector<Keluhan> daftarKeluhan;

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
                            // TODO: tampilkan daftar penghuni
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
                            // TODO: pembayaran kost (input tagihan baru & tandai lunas)
                            int userId, nominal;
                            string bulan;
                            cout << "Masukkan ID User : ";
                            cin >> userId;
                            cin.ignore();
                            cout << "Bulan            : ";
                            getline(cin, bulan);
                            cout << "Nominal (Rp)     : ";
                            cin >> nominal;

                            int idBaru = daftarPembayaran.size() + 1;
                            daftarPembayaran.push_back({idBaru, userId, bulan, nominal, false});
                            cout << "Tagihan tersimpan dengan ID: " << idBaru << " (Status: Belum Lunas)\n";
                            break;
                        }
                        case 3: {
                            cout << "Masuk ke menu ticket keluhan.\n";
                            menuTicketAdmin();
                            break;
                        }
                        case 4: {
                            cout << "Masuk ke menu laporan pembayaran.\n";
                            // TODO: laporan pembayaran
                            int totalLunas = 0, totalBelum = 0;
                            for (const auto& p : daftarPembayaran) {
                                cout << "ID #" << p.id << " | User ID: " << p.userId
                                     << " | " << p.bulan << " | Rp" << p.nominal
                                     << " | " << (p.lunas ? "LUNAS" : "BELUM LUNAS") << "\n";
                                if (p.lunas) totalLunas += p.nominal;
                                else totalBelum += p.nominal;
                            }
                            cout << "Total Lunas      : Rp" << totalLunas << "\n";
                            cout << "Total Belum Lunas: Rp" << totalBelum << "\n";
                            break;
                        }
                        case 5: { //blm ditambahin calling function buat manajemen kamar
                            system("cls");
                            cout << "============================\n";
                            cout << "Masuk ke menu manajemen kamar.\n";
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