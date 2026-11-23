#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string namaPelanggan;
    double totalBelanjaKotor, diskonPersen = 0.0, besaranDiskon, totalPembayaran;
    string keteranganBonus = "Tidak ada";

    cout << "======= SISTEM HITUNG DISKON KASIR MINIMARKET ========" << endl;

    cout << "Masukkan Nama Pelanggan      : ";
    getline(cin, namaPelanggan);
    cout << "Masukkan Total Belanja Kotor : Rp";
    cin >> totalBelanjaKotor;

    if (totalBelanjaKotor >= 500000) {
        diskonPersen = 0.20; 
        keteranganBonus = "Voucher Belanja Rp 50.000";
    } else if (totalBelanjaKotor >= 200000) {
        diskonPersen = 0.10; 
        keteranganBonus = "Tidak ada";
    } else {
        diskonPersen = 0.00; 
        keteranganBonus = "Tidak ada";
    }

    besaranDiskon = totalBelanjaKotor * diskonPersen;
    totalPembayaran = totalBelanjaKotor - besaranDiskon;

    cout << "\n ======== STRIP PEMBAYARAN ========" << endl;
    cout << fixed << setprecision(0);
    cout << "Nama Pelanggan              : " << namaPelanggan << endl;
    cout << "Total Belanja Sebelum Diskon: Rp" << totalBelanjaKotor << endl;
    cout << "Besaran Diskon              : Rp" << besaranDiskon << endl;
    cout << "Total Pembayaran Akhir      : Rp" << totalPembayaran << endl;
    cout << "Keterangan Bonus            : " << keteranganBonus << endl;
    
    return 0;
}