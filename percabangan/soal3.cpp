#include <iostream>

using namespace std;

int main(){
    float bil1, bil2;
    int operasi;

    cout << "========= Kalkulator Sederhana ========" << endl;
    cout << "Masukkan Bilangan 1 : ";
    cin >> bil1;
    cout << "Masukkan Bilangan 2 : ";
    cin >> bil2;

    cout << "Operasi Matematika" << endl;
    cout << "1. Penjumlahan " << endl;
    cout << "2. Pengurangan " << endl;
    cout << "3. Pembagian " << endl;
    cout << "4. Perkalian " << endl;

    cout << "Pilih Operasi Dengan Angka 1-4 : ";
    cin >> operasi;

    if(operasi < 1 || operasi > 4){
        cout << "Masukkan Pilihan yang benar";
    }

    switch(operasi){
        case 1:{
            cout << "Hasil Operasi Penjumlahan : " << bil1 + bil2;
            break;
        }
        case 2:{
            cout << "Hasil Operasi Pengurangan : " << bil1 - bil2;
            break;
        }
        case 3:{
            if (bil2 != 0){
                cout << "Hasil Operasi Pembagian : " << bil1 / bil2;
            }else{
                cout << "Masukkan angka bil2 selain 0";
            }
            break;
        }
        case 4:{
            cout << "Hasil Operasi Perkalian : " << bil1 * bil2;
            break;
        }
    }
}