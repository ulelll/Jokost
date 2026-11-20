#ifndef KAMAR_H
#define KAMAR_H

#include <string>
#include <vector>
#include "../User/user.h"

using namespace std;

class Kamar {
private:
    int nomorKamar;
    string status;

public:
    Kamar(int nomorKamar);

    int getNomorKamar() const;
    string getStatus() const;
    void setStatus(const string& status);

    bool cekKetersediaan() const;
    void lihatKamar(const vector<User>& daftarUser) const;
};

vector<Kamar> buatDataKamar(const vector<User>& daftarUser);
void menuManajemenKamar(vector<Kamar>& daftarKamar, const vector<User>& daftarUser);

#endif