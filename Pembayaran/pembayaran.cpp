#include "pembayaran.h"
#include "../input.h"
#include <iostream>
#include <cctype>

using namespace std;


static string cariNama(const vector<User>& daftarUser, int userId) {
    for (const auto& u : daftarUser)
        if (u.getId() == userId) return u.getNama();
    return "-";
}

static bool userAda(const vector<User>& daftarUser, int userId) {
    for (const auto& u : daftarUser)
        if (u.getId() == userId) return true;
    return false;
}

void tambahTagihan(vector<Pembayaran>& daftar, const vector<User>& daftarUser) {
    int userId = readInt("Masukkan ID User : ");
    if (!userAda(daftarUser, userId)) {
        cout << "ID user tidak ditemukan!\n";
        return;
    }

    string bulan = readString("Bulan            : ");
    if (bulan.empty()) {
        cout << "Bulan tidak boleh kosong!\n";
        return;
    }

    int nominal = readInt("Nominal (Rp)     : ");
    if (nominal <= 0) {
        cout << "Nominal harus lebih dari 0!\n";
        return;
    }

    // ID = ID terbesar + 1 
    int idBaru = 1;
    for (const auto& p : daftar)
        if (p.id >= idBaru) idBaru = p.id + 1;

    daftar.push_back({idBaru, userId, bulan, nominal, false});
    cout << "Tagihan " << cariNama(daftarUser, userId) << " (" << bulan
         << ") tersimpan dengan ID: " << idBaru << " (Status: Belum Lunas)\n";
}

void tandaiLunas(vector<Pembayaran>& daftar) {
    if (daftar.empty()) {
        cout << "Belum ada tagihan.\n";
        return;
    }

    int id = readInt("Masukkan ID tagihan yang dilunasi (0 untuk batal): ");
    if (id == 0) return;

    for (auto& p : daftar) {
        if (p.id == id) {
            if (p.lunas) cout << "Tagihan sudah lunas sebelumnya.\n";
            else {
                p.lunas = true;
                cout << "Tagihan ID " << id << " ditandai LUNAS.\n";
            }
            return;
        }
    }
    cout << "ID tagihan tidak ditemukan.\n";
}

void laporanPembayaran(const vector<Pembayaran>& daftar, const vector<User>& daftarUser) {
    if (daftar.empty()) {
        cout << "Belum ada data pembayaran.\n";
        return;
    }

    long long totalLunas = 0, totalBelum = 0;
    int jumlahLunas = 0, jumlahBelum = 0;

    cout << "========== LAPORAN PEMBAYARAN ==========\n";
    for (const auto& p : daftar) {
        cout << "ID #" << p.id
             << " | " << cariNama(daftarUser, p.userId) << " (ID: " << p.userId << ")"
             << " | " << p.bulan
             << " | Rp" << p.nominal
             << " | " << (p.lunas ? "LUNAS" : "BELUM LUNAS") << "\n";
        if (p.lunas) { totalLunas += p.nominal; jumlahLunas++; }
        else         { totalBelum += p.nominal; jumlahBelum++; }
    }
    cout << "----------------------------------------\n";
    cout << "Lunas       : " << jumlahLunas << " tagihan | Rp" << totalLunas << "\n";
    cout << "Belum Lunas : " << jumlahBelum << " tagihan | Rp" << totalBelum << "\n";
    cout << "Total Tagihan: Rp" << (totalLunas + totalBelum) << "\n";
    cout << "========================================\n";
}

//tidak case sensitive
static string kecil(string s) {
    for (auto& c : s) c = (char)tolower((unsigned char)c);
    return s;
}

void daftarStatusBayar(const vector<Pembayaran>& daftar, const vector<User>& daftarUser) {
    if (daftarUser.empty()) {
        cout << "Belum ada data penghuni.\n";
        return;
    }

    string bulan = readString("Bulan (kosongkan untuk semua bulan): ");

    vector<string> sudah, belum, tanpaTagihan;

    for (const auto& u : daftarUser) {
        int jumlah = 0;
        long long sisa = 0;
        for (const auto& p : daftar) {
            if (p.userId != u.getId()) continue;
            if (!bulan.empty() && kecil(p.bulan) != kecil(bulan)) continue;
            jumlah++;
            if (!p.lunas) sisa += p.nominal;
        }

        string baris = u.getNama() + " (ID: " + to_string(u.getId()) +
                       ", Kamar " + to_string(u.getNomorKamar()) + ")";
        if (jumlah == 0)      tanpaTagihan.push_back(baris);
        else if (sisa == 0)   sudah.push_back(baris);
        else                  belum.push_back(baris + " - sisa Rp" + to_string(sisa));
    }

    cout << "\n===== STATUS PEMBAYARAN"
         << (bulan.empty() ? " (SEMUA BULAN)" : " - " + bulan) << " =====\n";

    cout << "\n[SUDAH BAYAR] (" << sudah.size() << ")\n";
    if (sudah.empty()) cout << "  -\n";
    for (const auto& s : sudah) cout << "  - " << s << "\n";

    cout << "\n[BELUM BAYAR] (" << belum.size() << ")\n";
    if (belum.empty()) cout << "  -\n";
    for (const auto& s : belum) cout << "  - " << s << "\n";

    cout << "\n[BELUM ADA TAGIHAN] (" << tanpaTagihan.size() << ")\n";
    if (tanpaTagihan.empty()) cout << "  -\n";
    for (const auto& s : tanpaTagihan) cout << "  - " << s << "\n";
    cout << "========================================\n";
}

void menuPembayaran(vector<Pembayaran>& daftar, const vector<User>& daftarUser) {
    cout << "1. Input tagihan baru\n2. Tandai tagihan lunas\n"
         << "3. Lihat siapa yang sudah / belum bayar\n0. Kembali\n";
    int pilih = readInt("Pilih: ");
    if (pilih == 1) tambahTagihan(daftar, daftarUser);
    else if (pilih == 2) tandaiLunas(daftar);
    else if (pilih == 3) daftarStatusBayar(daftar, daftarUser);
    else if (pilih != 0) cout << "Pilihan tidak valid!\n";
}