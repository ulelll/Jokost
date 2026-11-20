#ifndef INPUT_H
#define INPUT_H
#include <iostream> 
#include <limits> 
#include <string> 

using namespace std;

//buat baca angka biar ga looping kalau user input bukan angka 
inline int readInt(const string& prompt){
    int nilai; 
    while (true){
        cout << prompt; 
        if (cin >> nilai){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nilai; 
        }
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input harus berupa angka! Silakan coba lagi.\n";
    }
}

inline string readString(const string& prompt){
    string s; 
    cout << prompt;
    getline(cin, s);
    return s; 
}

#endif 