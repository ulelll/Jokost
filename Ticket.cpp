#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class Ticket {
private:
    int idTicket;
    int idPenghuni;
    string deskripsi;
    string status;

    static int counterId;

public:
    Ticket() : idTicket(0), idPenghuni(0), deskripsi(""), status("") {}

    void buatTicket(int idPenghuniInput, const string& deskripsiInput) {
        idTicket   = counterId++;
        idPenghuni = idPenghuniInput;
        deskripsi  = deskripsiInput;
        status     = "Pending";
    }

    void lihatTicket() const {
        cout << "ID Ticket   : " << idTicket   << endl;
        cout << "ID Penghuni : " << idPenghuni << endl;
        cout << "Deskripsi   : " << deskripsi  << endl;
        cout << "Status      : " << status     << endl;
        cout << "----------------------------------" << endl;
    }

    bool ubahStatusTicket(const string& statusBaru) {
        if (statusBaru == "Pending" || statusBaru == "Diproses" || statusBaru == "Selesai") {
            status = statusBaru;
            return true;
        }
        return false;
    }

    int getIdTicket()   const { return idTicket; }
    int getIdPenghuni() const { return idPenghuni; }
    string getStatus()  const { return status; }
};

int Ticket::counterId = 1;

vector<Ticket> daftarTicket;

bool penghuniTerdaftar(int idPenghuni) {
    return idPenghuni > 0;
}

int inputAngka(const string& prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input harus berupa angka!" << endl;
    }
}

void userBuatTicket() {
    int idPenghuni = inputAngka("Masukkan ID Penghuni : ");
    if (!penghuniTerdaftar(idPenghuni)) {
        cout << "ID penghuni tidak terdaftar!" << endl;
        return;
    }

    string deskripsi;
    cout << "Deskripsi keluhan     : ";
    getline(cin, deskripsi);
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

void userLihatTicket() {
    int idPenghuni = inputAngka("Masukkan ID Penghuni : ");
    if (!penghuniTerdaftar(idPenghuni)) {
        cout << "ID penghuni tidak terdaftar!" << endl;
        return;
    }

    bool ada = false;
    cout << "\n=== Ticket Milik Anda ===" << endl;
    for (const Ticket& t : daftarTicket) {
        if (t.getIdPenghuni() == idPenghuni){
            t.lihatTicket();
            ada = true;
        }
    }
    if (!ada) cout << "Belum ada ticket." << endl;
}

void adminLihatSemuaTicket() {
    cout << "\n=== Daftar Semua Ticket ===" << endl;
    if (daftarTicket.empty()) {
        cout << "Belum ada ticket masuk." << endl;
        return;
    }
    for (const Ticket& t : daftarTicket) t.lihatTicket();
}

// Menampilkan semua ticket milik satu penghuni. Return true jika ada.
bool adminCariTicketByPenghuni(int idPenghuni) {
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

void prosesUbahStatus(int idTicket) {
    for (Ticket& t : daftarTicket) {
        if (t.getIdTicket() == idTicket) {
            cout << "Status saat ini : " << t.getStatus() << endl;
            cout << "1. Pending\n2. Diproses\n3. Selesai\n";
            int pilih = inputAngka("Pilih status baru : ");
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

void adminUbahStatus() {
    if (daftarTicket.empty()) {
        cout << "Belum ada ticket masuk." << endl;
        return;
    }

    cout << "\nCari ticket berdasarkan:" << endl;
    cout << "1. ID Ticket" << endl;
    cout << "2. ID Penghuni" << endl;
    int cara = inputAngka("Pilih : ");

    if (cara == 1) {
        int idTicket = inputAngka("Masukkan ID Ticket : ");
        prosesUbahStatus(idTicket);
    } else if (cara == 2) {
        int idPenghuni = inputAngka("Masukkan ID Penghuni : ");
        if (adminCariTicketByPenghuni(idPenghuni)) {
            int idTicket = inputAngka("Masukkan ID Ticket yang ingin diubah : ");
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

void menuTicketUser() {
    int pilih;
    do {
        cout << "\n=== TICKET KELUHAN (USER) ===" << endl;
        cout << "1. Buat Ticket Keluhan" << endl;
        cout << "2. Lihat Status Keluhan" << endl;
        cout << "0. Kembali" << endl;
        pilih = inputAngka("Pilih : ");
        switch (pilih) {
            case 1: userBuatTicket(); break;
            case 2: userLihatTicket(); break;
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
        pilih = inputAngka("Pilih : ");
        switch (pilih) {
            case 1: adminLihatSemuaTicket(); break;
            case 2: adminUbahStatus(); break;
            case 0: break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilih != 0);
}

int main() {
    int peran;
    do {
        cout << "\n=== TEST MODUL TICKET ===" << endl;
        cout << "1. Masuk sebagai User" << endl;
        cout << "2. Masuk sebagai Admin" << endl;
        cout << "0. Keluar" << endl;
        peran = inputAngka("Pilih : ");
        if      (peran == 1) menuTicketUser();
        else if (peran == 2) menuTicketAdmin();
    } while (peran != 0);
    return 0;
}
