#ifndef USER_H  
#define USER_H
 
#include <string>
#include <vector>
using namespace std;

class User {
    private:
    int id; 
        string nama; 
        string username; 
        string password; 
        string nomorHp; 
        int nomorKamar; 
    public: 
    User(int id, const string& nama, const string& username, const string& password, const string& nomorHp, int nomorKamar);

    int getId() const; 
    string getNama() const;
    string getUsername() const;
    string getNomorHp() const;
    int getNomorKamar() const;

    bool checkPassword(const string& input) const;

    void setNama(const string& nama);
    void setNomorHp(const string& nomorHp);
    void setNomorKamar(int nomorKamar);

    void tampil() const; 
    
    
};

vector<User> buatDataUser(); 

#endif 