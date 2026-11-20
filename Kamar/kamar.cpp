#include <iostream>
#include "kamar.h"

using namespace std;

Kamar::Kamar(int nomorKamar) {
    this->nomorKamar = nomorKamar;
    this->status = "Kosong";
}

int Kamar::getNomorKamar() const {
    return nomorKamar;
}

string Kamar::getStatus() const {
    return status;
}

void Kamar::setStatus(const string& status) {
    this->status = status;
}

bool Kamar::cekKetersediaan() const {
    return status == "Kosong";
}

void Kamar::lihatKamar(const vector<User>& daftarUser) const {
    string namaPenghuni = "-";
    for (size_t i = 0; i < daftarUser.size(); i++) {
        if (daftarUser[i].getNomorKamar() == nomorKamar) {
            namaPenghuni = daftarUser[i].getNama();
            break;
        }
    }

    cout << "Kamar " << nomorKamar
         << " | Status: " << status
         << " | Penghuni: " << namaPenghuni << "\n";
}

vector<Kamar> buatDataKamar(const vector<User>& daftarUser) {
    vector<Kamar> daftarKamar;

    for (int i = 1; i <= 5; i++) {
        Kamar kamarBaru(i);
        for (size_t j = 0; j < daftarUser.size(); j++) {
            if (daftarUser[j].getNomorKamar() == i) {
                kamarBaru.setStatus("Terisi");
                break;
            }
        }
        daftarKamar.push_back(kamarBaru);
    }

    return daftarKamar;
}

void menuManajemenKamar(vector<Kamar>& daftarKamar, const vector<User>& daftarUser) {
    cout << "============================\n";
    cout << "  JOKOST MANAGEMENT SYSTEM  \n";
    cout << "============================\n";
    cout << "===== MANAJEMEN KAMAR ======\n";

    for (size_t i = 0; i < daftarKamar.size(); i++) {
        bool adaPenghuni = false;
        for (size_t j = 0; j < daftarUser.size(); j++) {
            if (daftarUser[j].getNomorKamar() == daftarKamar[i].getNomorKamar()) {
                adaPenghuni = true;
                break;
            }
        }
        daftarKamar[i].setStatus(adaPenghuni ? "Terisi" : "Kosong");
        daftarKamar[i].lihatKamar(daftarUser);
    }

    cout << "============================\n";
}