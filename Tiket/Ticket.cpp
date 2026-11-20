#include "tiket.h"
#include "../input.h"
#include <iostream>

using namespace std;


int Ticket::counterId = 1;

Ticket::Ticket() : idTicket(0), idPenghuni(0), deskripsi(""), status("") {}

void Ticket::buatTicket(int idPenghuniInput, const string& deskripsiInput) {
    idTicket   = counterId++;
    idPenghuni = idPenghuniInput;
    deskripsi  = deskripsiInput;
    status     = "Pending";
}

void Ticket::lihatTicket() const {
    cout << "ID Ticket   : " << idTicket   << endl;
    cout << "ID Penghuni : " << idPenghuni << endl;
    cout << "Deskripsi   : " << deskripsi  << endl;
    cout << "Status      : " << status     << endl;
    cout << "----------------------------------" << endl;
}

bool Ticket::ubahStatusTicket(const string& statusBaru) {
    if (statusBaru == "Pending" || statusBaru == "Diproses" || statusBaru == "Selesai") {
        status = statusBaru;
        return true;
    }
    return false;
}

vector<Ticket> daftarTicket;

static bool penghuniTerdaftar(int idPenghuni) {
    return idPenghuni > 0;
}

static bool adminCariTicketByPenghuni(int idPenghuni) {
    bool ada = false;
    cout << "\n=== Ticket Penghuni ID " << idPenghuni << " ===" << endl;
    for (const Ticket& t : daftarTicket) {
        if (t.getIdPenghuni() == idPenghuni) {
            t.lihatTicket();
            ada = true;
        }
    }
    if (!ada) cout << "Tidak ada ticket untuk penghuni tersebut." << endl;
    return ada;
}

static void prosesUbahStatus(int idTicket) {
    for (Ticket& t : daftarTicket) {
        if (t.getIdTicket() == idTicket) {
            cout << "Status saat ini : " << t.getStatus() << endl;
            cout << "1. Pending\n2. Diproses\n3. Selesai\n";
            int pilih = readInt("Pilih status baru : ");
            string statusBaru;
            if      (pilih == 1) statusBaru = "Pending";
            else if (pilih == 2) statusBaru = "Diproses";
            else if (pilih == 3) statusBaru = "Selesai";

            if (t.ubahStatusTicket(statusBaru))
                cout << "Status berhasil diubah menjadi " << statusBaru << endl;
            else
                cout << "Pilihan tidak valid!" << endl;
            return;
        }
    }
    cout << "Ticket dengan ID " << idTicket << " tidak ditemukan." << endl;
}

//fitur user

void userBuatTicket(int idPenghuni) {
    string deskripsi = readString("Deskripsi keluhan     : ");
    if (deskripsi.empty()) {
        cout << "Deskripsi tidak boleh kosong!" << endl;
        return;
    }

    Ticket t;
    t.buatTicket(idPenghuni, deskripsi);
    daftarTicket.push_back(t);
    cout << "Ticket berhasil dibuat. ID Ticket: " << t.getIdTicket()
         << " (Status: Pending)" << endl;
}

void userLihatTicket(int idPenghuni) {
    bool ada = false;
    cout << "\n=== Ticket Milik Anda ===" << endl;
    for (const Ticket& t : daftarTicket) {
        if (t.getIdPenghuni() == idPenghuni) {
            t.lihatTicket();
            ada = true;
        }
    }
    if (!ada) cout << "Belum ada ticket." << endl;
}


//fitur admin
void adminLihatSemuaTicket() {
    cout << "\n=== Daftar Semua Ticket ===" << endl;
    if (daftarTicket.empty()) {
        cout << "Belum ada ticket masuk." << endl;
        return;
    }
    for (const Ticket& t : daftarTicket) t.lihatTicket();
}

void adminUbahStatus() {
    if (daftarTicket.empty()) {
        cout << "Belum ada ticket masuk." << endl;
        return;
    }

    cout << "\nCari ticket berdasarkan:" << endl;
    cout << "1. ID Ticket" << endl;
    cout << "2. ID Penghuni" << endl;
    int cara = readInt("Pilih : ");

    if (cara == 1) {
        int idTicket = readInt("Masukkan ID Ticket : ");
        prosesUbahStatus(idTicket);
    } else if (cara == 2) {
        int idPenghuni = readInt("Masukkan ID Penghuni : ");
        if (adminCariTicketByPenghuni(idPenghuni)) {
            int idTicket = readInt("Masukkan ID Ticket yang ingin diubah : ");
            bool milikPenghuni = false;
            for (const Ticket& t : daftarTicket) {
                if (t.getIdTicket() == idTicket && t.getIdPenghuni() == idPenghuni)
                    milikPenghuni = true;
            }
            if (milikPenghuni) prosesUbahStatus(idTicket);
            else cout << "ID Ticket tidak ada di daftar penghuni tersebut." << endl;
        }
    } else {
        cout << "Pilihan tidak valid!" << endl;
    }
}


//menu
void menuTicketUser(int idPenghuni) {
    int pilih;
    do {
        cout << "\n=== TICKET KELUHAN (USER) ===" << endl;
        cout << "1. Buat Ticket Keluhan" << endl;
        cout << "2. Lihat Status Keluhan" << endl;
        cout << "0. Kembali" << endl;
        pilih = readInt("Pilih : ");
        switch (pilih) {
            case 1: userBuatTicket(idPenghuni); break;
            case 2: userLihatTicket(idPenghuni); break;
            case 0: break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilih != 0);
}

void menuTicketAdmin() {
    int pilih;
    do {
        cout << "\n=== TICKET KELUHAN (ADMIN) ===" << endl;
        cout << "1. Lihat Daftar Keluhan" << endl;
        cout << "2. Ubah Status Keluhan" << endl;
        cout << "0. Kembali" << endl;
        pilih = readInt("Pilih : ");
        switch (pilih) {
            case 1: adminLihatSemuaTicket(); break;
            case 2: adminUbahStatus(); break;
            case 0: break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilih != 0);
}