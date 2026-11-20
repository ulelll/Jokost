#include "user.h"
#include <iostream> 
using namespace std;

User::User(int id, const string& nama, const string& username, const string& password, const string& nomorHp, int nomorKamar) 
    : id(id), nama(nama), username(username), password(password), nomorHp(nomorHp), nomorKamar(nomorKamar) {}

int User::getId() const { return id; }
string User::getNama() const { return nama;}
string User:: getUsername() const { return username;}
string User:: getNomorHp() const { return nomorHp;}
int User:: getNomorKamar() const { return nomorKamar;}

bool User::checkPassword(const string& input) const {
    return password == input; 
}

void User::setNama(const string& nama) { this -> nama = nama;}
void User::setNomorHp(const string& nomorHp) { this -> nomorHp = nomorHp;}
void User::setNomorKamar(int nomorKamar) { this -> nomorKamar = nomorKamar;}

void User::tampil() const {
    cout << "ID pengguna: " << id << endl; 
    cout << "Nama: " << nama << endl; 
    cout << "Username: " << username << endl; 
    cout << "Nomor Hp: " << nomorHp << endl; 
    cout << "Nomor Kamar: " << nomorKamar << endl; 
}

vector <User> buatDataUser() {
    vector <User> daftar; 
    daftar.push_back(User(1001, "Yui",     "yui1",     "yui123",     "812345678", 1));
    daftar.push_back(User(1002, "Mio",     "mio2",     "mio123",     "823456789", 2));
    daftar.push_back(User(1003, "Ritsu",   "ritsu3",   "ritsu123",   "834567891", 3));
    daftar.push_back(User(1004, "Tsumogi", "tsumogi4", "tsumogi123", "845678912", 4));
    daftar.push_back(User(1005, "Azusa",   "azusa5",   "azusa123",   "856789123", 5));

    return daftar; 
}