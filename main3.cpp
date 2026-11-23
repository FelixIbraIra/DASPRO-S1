#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int choice;
    double celcius;

    const double fahrenheit_kali = 1.8;
    const double fahrenheit_tambah = 32;
    const double kelvinya = 273.15;

    cout << "Konversi Celcius" << endl;;;
    cout <<"Masukkan Celcius : ";
    cin >> celcius ; 

    cout <<"Pilihan Konversi" << endl;
    cout << "1. Celcius ke Fahrenheit " << ((celcius * fahrenheit_kali) + fahrenheit_tambah) << endl;
    cout << "2. Celcius ke Kelvin " <<  celcius + kelvinya  << endl;

    // cout << "Pilih dengan ketik angka : ";
    // cin >> choice;

    // if(choice < 1 && choice > 2){
    //     cout << "Pilihan kamu gak ada";
    // }

    // switch (choice){
    //     case 1:{
    //         double fahrenheit = (celcius * fahrenheit_kali) + fahrenheit_tambah;
    //         cout << "Hasil Konversi = " << fahrenheit << fixed << setprecision(5);
    //         break;
    //     }
    //     case 2:{
    //         double kelvin = celcius + kelvinya ;
    //         cout << "Hasil Konversi = " << kelvin;
    //         break;
    //     }
    // }
}