#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    double nilai;
    double totalNilai = 0;
    double nilaiTertinggi;
    double nilaiTerendah;
    int lulus = 0;
    int tidakLulus = 0;

    cout << "======== PROGRAM REKAP NILAI MAHASISWA ========\n";

    cout << "Masukkan jumlah mahasiswa (N): ";
    cin >> N;

    if (N <= 0) {
        cout << "\n[Peringatan] Jumlah mahasiswa harus lebih besar dari 0!\n";
        return 0;
    }


    for (int i = 1; i <= N; i++) {
        cout << "Masukkan nilai mahasiswa ke-" << i << ": ";
        cin >> nilai;

        totalNilai += nilai;

        if (i == 1) {
            nilaiTertinggi = nilai;
            nilaiTerendah = nilai;
        } else {
            if (nilai > nilaiTertinggi) {
                nilaiTertinggi = nilai;
            }
            if (nilai < nilaiTerendah) {
                nilaiTerendah = nilai;
            }
        }

        if (nilai >= 60) {
            lulus++;
        } else {
            tidakLulus++;
        }
    }

    double rataRata = totalNilai / N;

    cout << "\n======== HASIL REKAPITULASI NILAI ========\n";
    cout << fixed << setprecision(2);
    cout << "Rata-Rata Kelas         : " << rataRata << endl;
    cout << "Nilai Tertinggi         : " << nilaiTertinggi << endl;
    cout << "Nilai Terendah          : " << nilaiTerendah << endl;
    cout << "Jumlah Mahasiswa Lulus  : " << lulus << " orang" << endl;
    cout << "Jumlah Tidak Lulus      : " << tidakLulus << " orang" << endl;

    return 0;
}