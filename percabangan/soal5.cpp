#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string golongan;
    double kwh;
    char subsidi;
    double biayaAdmin = 0;
    double tarif1 = 0, tarif2 = 0, tarif3 = 0;
    double biayaListrik = 0;
    double diskonSubsidi = 0;

    cout << "====== PROGRAM HITUNG TAGIHAN LISTRIK ======" << endl;

    cout << "Masukkan Golongan Pelanggan (R1 / R2 / B1) : ";
    cin >> golongan;

    cout << "Masukkan Jumlah Pemakaian (kWh)          : ";
    cin >> kwh;

    cout << "Status Subsidi (Y / N)                   : ";
    cin >> subsidi;

    subsidi = toupper(subsidi);

    if ((golongan != "R1" && golongan != "R2" && golongan != "B1") || 
        (kwh < 0) || 
        (subsidi != 'Y' && subsidi != 'N')) {
        cout << "\n Masukkan Data Yang Benar" << endl;
        return 1; 
    }

    if (golongan == "R1") {
        tarif1 = 1500;
        tarif2 = 2000;
        tarif3 = 2500;
    } else if (golongan == "R2") {
        tarif1 = 1800;
        tarif2 = 2300;
        tarif3 = 2800;
    } else if (golongan == "B1") {
        tarif1 = 2000;
        tarif2 = 2500;
        tarif3 = 3000;
    }

    if (kwh <= 100) {
        biayaListrik = kwh * tarif1;
    } else if (kwh <= 300) {
        biayaListrik = (100 * tarif1) + ((kwh - 100) * tarif2);
    } else { 
        biayaListrik = (100 * tarif1) + (200 * tarif2) + ((kwh - 300) * tarif3);
    }

    if (subsidi == 'Y') {
        if (kwh <= 300) {
            diskonSubsidi = 0.20 * biayaListrik; 
        } else {
            diskonSubsidi = 0.10 * biayaListrik; 
        }
    }

    if (kwh > 500) {
        biayaAdmin = 10000;
    }

    double totalBayar = (biayaListrik - diskonSubsidi) + biayaAdmin;

    cout << fixed << setprecision(0);
    cout << "========= RINCIAN TAGIHAN =========" << endl;
    cout << "Golongan Pelanggan  : " << golongan << endl;
    cout << "Pemakaian Listrik   : " << kwh << " kWh" << endl;
    cout << "Status Subsidi      : " << (subsidi == 'Y' ? "Ya" : "Tidak") << endl;
    cout << "---------------------------------------" << endl;
    cout << "Biaya Listrik Kotor : Rp " << biayaListrik << endl;
    cout << "Potongan Subsidi    : Rp " << diskonSubsidi << endl;
    cout << "Biaya Administrasi  : Rp " << biayaAdmin << endl;
    cout << "---------------------------------------" << endl;
    cout << "TOTAL PEMBAYARAN    : Rp " << totalBayar << endl;
    cout << "=======================================" << endl;

    return 0;
}