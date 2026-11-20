#ifndef TIKET_H
#define TIKET_H

#include <string>
#include <vector>

class Ticket {
private:
    int idTicket;
    int idPenghuni;
    std::string deskripsi;
    std::string status;

    static int counterId;

public:
    Ticket();

    void buatTicket(int idPenghuniInput, const std::string& deskripsiInput);
    void lihatTicket() const;
    bool ubahStatusTicket(const std::string& statusBaru);

    int getIdTicket()   const { return idTicket; }
    int getIdPenghuni() const { return idPenghuni; }
    std::string getStatus() const { return status; }
};

//untuk nyimpen ticket 
extern std::vector<Ticket> daftarTicket;

//fitur user
void userBuatTicket();
void userLihatTicket();

//fitur admin
void adminLihatSemuaTicket();
void adminUbahStatus();

//menu
void menuTicketUser();
void menuTicketAdmin();

#endif