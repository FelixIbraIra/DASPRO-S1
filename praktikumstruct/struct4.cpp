#include <iostream>

using namespace std;

struct DataNilai{
    string nim;
    string nama;
    int nilai;
};

int main(){
    DataNilai mahasiswa[5];
    int jumlahData = 0;

    char jawab;
    cout << "Input data Mahasiswa" << endl;
    do{
        cout << "\nData ke-" << (jumlahData + 1) << endl;
        cout << "Masukkan NIM : ";
        cin >> mahasiswa[jumlahData].nim;
        cout << "Masukkan Nama : ";
        cin >> mahasiswa[jumlahData].nama;
        cout << "Masukkan Nilai : ";
        cin >> mahasiswa[jumlahData].nilai;
        jumlahData++;

        if (jumlahData >= 5){
            cout << "Data sudah penuh, tidak bisa menambah data lagi." << endl;
            break;
        }
        cout << "Apakah ingin menambah data? (y/n) : ";
        cin >> jawab;
    } while(jawab == 'y' || jawab == 'Y');

    cout << "\nDaftar Mahasiswa" << endl;
    cout << "No\tNIM\tNama\tNilai" << endl;
    for (int i = 0; i < jumlahData; i++){
        cout << mahasiswa[i].nim << "\t" 
             << mahasiswa[i].nama << "\t" 
             << mahasiswa[i].nilai << endl;
    }
    return 0;
}