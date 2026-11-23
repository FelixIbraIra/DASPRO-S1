#include <iostream>

using namespace std;

int main(){
    int harga = 50000;
    int jumlah ;
    double diskon = 30/100;

    cout << "Menghitunga Jumlah Barang dan Diskon Setelahnya" << endl;
    cout << "Harga Barang : " << harga << "Rp" << endl;
    cout << "Diskon : 30% " << endl;
    cout << "Masukkan Jumlah Barang : ";
    cin >> jumlah;
    int totalharga = harga * jumlah;
    cout << "Total Harga sebelum diskon :" << totalharga << endl;
    cout << "Total Harga Setelah Diskon : " <<  totalharga * diskon;
}