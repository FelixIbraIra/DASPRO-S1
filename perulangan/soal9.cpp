#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double targetTabungan;
    double setoranBulan;
    double saldo = 0;
    int bulan = 0;

    cout << "======= PROGRAM SIMULASI TABUNGAN =======\n";

    cout << "Masukkan target tabungan (Rp): ";
    cin >> targetTabungan;

    if (targetTabungan <= 0) {
        cout << "\n[Peringatan] Target tabungan harus lebih besar dari 0!\n";
        return 0;
    }

    while (saldo < targetTabungan && bulan < 24) {
        bulan++;
        cout << "Masukkan setoran bulan ke-" << bulan << " (Rp): ";
        cin >> setoranBulan;

        if (setoranBulan <= 0) {
            cout << "Setoran harus lebih besar dari 0. Silakan input ulang.\n";
            bulan--;
            continue;
        }

        saldo += setoranBulan;

        cout << fixed << setprecision(2);
        cout << "-> Saldo bulan ke-" << bulan << " saat ini: Rp " << saldo << "\n\n";
    }

    cout << "======== HASIL SIMULASI TABUNGAN ========\n";

    if (saldo >= targetTabungan) {
        cout << "Selamat! Target tabungan Anda tercapai.\n";
        cout << "Jumlah bulan yang diperlukan : " << bulan << " bulan\n";
        cout << "Total tabungan akhir         : Rp " << saldo << endl;
    } else {
        cout << "Target tabungan tidak dapat dicapai dalam batas maksimal 24 bulan.\n";
        cout << "Total tabungan yang terkumpul: Rp " << saldo << endl;
        cout << "Kekurangan target            : Rp " << (targetTabungan - saldo) << endl;
    }
    return 0;
}