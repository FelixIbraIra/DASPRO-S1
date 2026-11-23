#include <iostream>
#include <iomanip>

using namespace std;

void luas_segiempat(){
    int lebar;
    int panjang;
    
    cout << "Menghitung Luas Segi Empat" << endl;
    cout << "Masukkan Lebar : ";
    cin >> lebar;
    cout << "Masukkan Panjang : ";
    cin >> panjang;
    
    int luas = panjang * lebar;
    
    cout << "Hasil Luas Segi Empat : " << luas;
}
void luas_lingkaran(){
    double pi = 3.14;
    int jari;

    cout << "Menghitung Luas Lingkarang" << endl;
    cout << "Masukkan jari : ";
    cin >> jari;

    int luas = pi * jari * jari;

    cout << "Hasil Luas Lingkaran : " << luas;
}

int main(){
    luas_segiempat();
    luas_lingkaran();
}
