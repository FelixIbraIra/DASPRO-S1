// Online C++ compiler (editor)
// Write and run C++ online using this editor.

#include <iostream>
using namespace  std;

void a(){
    int nilai [5] = {80,70,82,90,77};

    cout << "Daftar nilai Mahasiswa : " << endl;
    for (int i = 0; i < 5 ; i++){
        cout << "Nilai indeks ke-" << i << " = " << nilai[i] << endl;
    }
}
void b(){
        int n;
    float total = 0, ratarata;

    cout << "Masukkan jumlah data : ";
    cin >> n;

    float nilai[n];

    for (int i = 0; i < n; i++ ){
        cout << "Masukkan Nilai Ke-" << (i + 1) << ": ";
        cin >> nilai[i];
        total += nilai[i];
    }
    ratarata = total / n;

    cout << "\nTotal Nilai = " << total << endl;
    cout << "Nilai Rata rata = " << ratarata << endl;
}

void c(){
        int n;
    cout << "Masukkan jumlah data : ";
    cin  >> n;

    int data[n];
    for(int i = 0; i< n; i++){
        cout << "Masukkan data ke-" << (i+1) << ": ";
        cin >> data[1];
    }

    int maks = data[0];
    for(int i = 0; i < n; i++){
        if (data[i] >  maks){
            maks = data[i];
        }
    }

    cout << "\nData terbesar adalah: " << maks << endl;
}
void membuatSegitiga(int tinggi){
        for(int i = 0; i < tinggi ; i++){
        for (int j = 0; j < i; j++){
            cout << " ";
        }
        for (int j = 2 * i; j < tinggi * 2 - 1; j++){
            cout << "*";
        }
        cout << endl;
    }
}

// void menghitungvolumetabung(){
//     const 
// }

const double PI = 3.14;

double volumetabung( double r, double t){
    double volume =  PI * r * r * t;
    return volume;
}
int main() {
    // int n;
    // cout<< "Membuat segitiga terbalik"<< endl ;
    // cout << "Masukkan tinggi segitiga : ";
    // cin >> n;
    // cout << endl;

    // membuatSegitiga(n);

    double r,t;
    cout <<  "menghitung  v tabung" <<  endl;
    cout << "masukkan jari jari : ";
    cin >> r;
    cout << "masukkan tinggi ";
    cin >> t;

    double hasil = volumetabung (r,t);
    cout << "\n volume tabung = " << hasil << endl;
}


