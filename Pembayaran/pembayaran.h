#ifndef PEMBAYARAN_H
#define PEMBAYARAN_H

#include <string>
#include <vector>
#include "../User/user.h"

struct Pembayaran {
    int id;
    int userId;
    std::string bulan;
    int nominal;
    bool lunas;
};

void tambahTagihan(std::vector<Pembayaran>& daftar, const std::vector<User>& daftarUser);
void tandaiLunas(std::vector<Pembayaran>& daftar);
void laporanPembayaran(const std::vector<Pembayaran>& daftar, const std::vector<User>& daftarUser);
void daftarStatusBayar(const std::vector<Pembayaran>& daftar, const std::vector<User>& daftarUser);
void menuPembayaran(std::vector<Pembayaran>& daftar, const std::vector<User>& daftarUser);

#endif