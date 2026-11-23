#include <iostream>

using namespace std;

int main() {
    int populasiAwal, targetPopulasi;
    cout << "======= PROGRAM SIMULASI POPULASI DOMBA =======\n";
    while (true) {
        cout << "Masukkan populasi awal domba (minimal 9): ";
        cin >> populasiAwal;

        if (populasiAwal >= 9) {
            break;
        }

        cout << "[Peringatan] Jumlah populasi awal minimal harus 9 ekor!\n\n";
    }

    while (true) {
        cout << "Masukkan target populasi domba: ";
        cin >> targetPopulasi;

        if (targetPopulasi >= populasiAwal) {
            break;
        }

        cout << "[Peringatan] Target populasi tidak boleh kurang dari populasi awal!\n\n";
    }

    int n = 0;
    int populasiSaatIni = populasiAwal;

    while (populasiSaatIni < targetPopulasi) {
        int lahir = populasiSaatIni / 3;
        int mati = populasiSaatIni / 4;

        populasiSaatIni = populasiSaatIni + lahir - mati;
        n++;
    }

    cout << "\nWaktu yang dibutuhkan (n tahun) : " << n << " tahun\n";
    cout << "Populasi akhir domba            : " << populasiSaatIni << " ekor\n";

    return 0;
}