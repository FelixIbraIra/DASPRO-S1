#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    double pendapatan;
    double totalPendapatan = 0;
    double pendapatanTertinggi = 0;
    double rataRata;
    int hariMelebihi1Juta = 0;

    cout << "======= PROGRAM ANALISIS PENJUALAN 7 HARI ======= \n";

    for (int hari = 1; hari <= 7; hari++) {
        cout << "Masukkan pendapatan hari ke-" << hari << " (Rp): ";
        cin >> pendapatan;

        totalPendapatan += pendapatan;

        if (hari == 1) {
            pendapatanTertinggi = pendapatan;
        } else if (pendapatan > pendapatanTertinggi) {
            pendapatanTertinggi = pendapatan;
        }
        if (pendapatan > 1000000) {
            hariMelebihi1Juta++;
        }
    }

    rataRata = totalPendapatan / 7;

    cout << "======= HASIL ANALISIS PENJUALAN ======= \n";
    cout << fixed << setprecision(2); 
    cout << "Total Pendapatan (7 Hari)  : Rp " << totalPendapatan << endl;
    cout << "Rata-Rata Pendapatan/Hari  : Rp " << rataRata << endl;
    cout << "Pendapatan Tertinggi       : Rp " << pendapatanTertinggi << endl;
    cout << "Jumlah Hari > Rp1.000.000  : " << hariMelebihi1Juta << " hari" << endl;

    return 0;
}