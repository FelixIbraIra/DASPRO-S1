#include <iostream>

using namespace std;

int main() {
    int N;

    cout << "========= PROGRAM PALINDROME PRIMA (1 SAMPAI N) =========\n";

    while (true) {
        cout << "Masukkan bilangan bulat positif (N): ";
        cin >> N;

        if (N > 0) {
            break;
        }

        cout << "[Peringatan] Nilai N harus lebih besar dari 0! Silakan masukkan ulang.\n\n";
    }

    int jumlahDitemukan = 0;
    int bilanganTerbesar = 0;
    long long totalPenjumlahan = 0;

    cout << "Daftar bilangan Prima Palindrome dari 1 s.d " << N << ":\n";

    for (int i = 1; i <= N; i++) {
        if (i <= 1) {
            continue;
        }

        bool adalahPrima = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                adalahPrima = false;
                break;
            }
        }

        if (!adalahPrima) {
            continue;
        }

        int temp = i;
        int reversed = 0;
        while (temp > 0) {
            int digit = temp % 10;
            reversed = (reversed * 10) + digit;
            temp /= 10;
        }

        if (i == reversed) {
            cout << i << " ";
            jumlahDitemukan++;
            bilanganTerbesar = i;
            totalPenjumlahan += i;
        }
    }

    cout << "\n========= HASIL REKAP =========\n";
    cout << "Jumlah bilangan ditemukan : " << jumlahDitemukan << endl;
    cout << "Bilangan terbesar         : " << bilanganTerbesar << endl;
    cout << "Total penjumlahan         : " << totalPenjumlahan << endl;

    return 0;
}