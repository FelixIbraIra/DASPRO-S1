#include <iostream>

using namespace std;

int main(){
    int operasi;

    cout << "========= Kalkulator Sederhana =========" << endl;
    cout << "1.Menghitung Volume Kubus" << endl;
    cout << "2.Menghitung Luas Lingkaran" << endl;
    cout << "3.Menghitung Volume Silinder" << endl;

    cout << "Masukkan Angka 1 - 3 untuk memilih operasi : ";
    cin >> operasi;

    switch (operasi){
        case 1:{
            int sisi;
            cout << "Masukkan Panjang Sisi Kubus : "; 
            cin >> sisi;
            int hasil = sisi * sisi * sisi;
            cout << "Hasil Volume Kubus dengan sisi " << sisi << " adalah : " << hasil;

            break;
        }
        case 2:{
            float jari;
            cout << "Masukkan Panjang Jari Jari: "; 
            cin >> jari ;
            float hasil = 3.14 * jari * jari;
            cout << "Hasil Luas Lingkaran dengan jari jari : " << jari << " adalah : " << hasil;
            break;
        }
        case 3:{
            float jari;
            float tinggi;
            cout << "Masukkan Panjang Jari Jari : "; 
            cin >> jari;
            cout << "Masukkan Panjang Tinggi Silinder : "; 
            cin >> tinggi;
            float hasil = 3.14 * jari * jari * tinggi;
            cout << "Hasil Volume Silinder dengan jari jari " << jari << " dan tinggi " << tinggi << " adalah : " << hasil;

            break;
        }
        default : {
            cout << "Masukkan Angka Yang Benar, Antara 1 - 3 ";
            break;
        }
    }
}