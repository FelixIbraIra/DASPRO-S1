#include <iostream>

using namespace std;

int main(){
    string pelanggan;
    int lembar;
    int hargalembar = 0;
    int totalbayar = 0;

    cout << "Fotokopi Ilham Jaya " << endl;
    cout << "Apakah Pelanggan : ";
    cin >> pelanggan;
    cout << "Masukkan Lembar jumlah fotokopi : ";
    cin >> lembar;

    if(pelanggan == "ya" || pelanggan == "iya"){
        hargalembar = 75 ;
        cout << "Harga / Lembar = Rp75 ";
    }else{
        if (lembar < 100){
            hargalembar = 150;
            cout << "Harga / Lembar = Rp150 ";
        }else if (lembar >= 100 && lembar <=200){
            hargalembar = 100;
            cout << "Harga / Lembar = Rp100 ";
        }else if (lembar > 200){
            hargalembar = 80;
            cout << "Harga / Lembar = Rp80 ";
        }
    }
    totalbayar = lembar * hargalembar;
    cout << "\nTotal yang harus dibayar: Rp " << totalbayar << endl;
    
    return 0;
}