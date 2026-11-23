#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

// ==========================================
// 1. KONSTANTA ATURAN BISNIS
// ==========================================
const int MAX_RESERVASI = 100;
const int JUMLAH_LAPANGAN = 3;
const int JAM_BUKA = 9;
const int JAM_TUTUP = 23;
const int HARGA_PER_JAM = 120000;

// ==========================================
// 2. STRUKTUR DATA (STRUCT)
// ==========================================
struct Reservasi {
    string namaPemesan;
    int nomorLapangan;
    int jamMulai;
    int durasi;
    int totalBiaya;
};

// ==========================================
// 3. DEKLARASI FUNGSI (PROTOTYPE)
// ==========================================
void tampilkanMenu();
int inputAngka(string pesan);
bool cekBentrok(const Reservasi daftar[], int jumlahData, int lapangan, int jamMulai, int durasi);
int cariIndexSlot(const Reservasi daftar[], int jumlahData, int lapangan, int jam);

void lihatJadwal(const Reservasi daftar[], int jumlahData);
void buatReservasi(Reservasi daftar[], int &jumlahData);
void cariPemesan(const Reservasi daftar[], int jumlahData);
void batalkanReservasi(Reservasi daftar[], int &jumlahData);

// ==========================================
// 4. FUNGSI UTAMA (MAIN)
// ==========================================
int main() {
    Reservasi daftarReservasi[MAX_RESERVASI];
    int jumlahData = 0;
    int pilihan;

    do {
        tampilkanMenu();
        pilihan = inputAngka("Pilih menu (1-5): ");
        cout << endl;

        switch (pilihan) {
            case 1:
                lihatJadwal(daftarReservasi, jumlahData);
                break;
            case 2:
                buatReservasi(daftarReservasi, jumlahData);
                break;
            case 3:
                cariPemesan(daftarReservasi, jumlahData);
                break;
            case 4:
                batalkanReservasi(daftarReservasi, jumlahData);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan Sistem Reservasi Futsal!" << endl;
                break;
            default:
                cout << "[!] Pilihan tidak valid. Silakan masukkan angka 1 sampai 5." << endl;
        }

        cout << endl;

    } while (pilihan != 5);

    return 0;
}

// ==========================================
// 5. IMPLEMENTASI FUNGSI BANTU
// ==========================================
int inputAngka(string pesan) {
    int nilai;
    while (true) {
        cout << pesan;
        cin >> nilai;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[!] Input tidak valid. Harap masukkan angka!" << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nilai;
        }
    }
}

bool cekBentrok(const Reservasi daftar[], int jumlahData, int lapangan, int jamMulai, int durasi) {
    int jamSelesaiBaru = jamMulai + durasi;

    for (int i = 0; i < jumlahData; i++) {
        if (daftar[i].nomorLapangan == lapangan) {
            int jamMulaiLama = daftar[i].jamMulai;
            int jamSelesaiLama = daftar[i].jamMulai + daftar[i].durasi;

            if (jamMulai < jamSelesaiLama && jamSelesaiBaru > jamMulaiLama) {
                return true;
            }
        }
    }
    return false;
}

int cariIndexSlot(const Reservasi daftar[], int jumlahData, int lapangan, int jam) {
    for (int i = 0; i < jumlahData; i++) {
        if (daftar[i].nomorLapangan == lapangan) {
            int jamSelesai = daftar[i].jamMulai + daftar[i].durasi;
            if (jam >= daftar[i].jamMulai && jam < jamSelesai) {
                return i;
            }
        }
    }
    return -1;
}

// ==========================================
// 6. IMPLEMENTASI FUNGSI MENU UTAMA
// ==========================================
void tampilkanMenu() {
    cout << "==========================================" << endl;
    cout << "     SISTEM RESERVASI LAPANGAN FUTSAL     " << endl;
    cout << "==========================================" << endl;
    cout << "1. Lihat Jadwal & Ketersediaan Lapangan" << endl;
    cout << "2. Buat Reservasi Baru" << endl;
    cout << "3. Cari Data Pemesan" << endl;
    cout << "4. Batalkan Reservasi" << endl;
    cout << "5. Keluar" << endl;
    cout << "==========================================" << endl;
}

void lihatJadwal(const Reservasi daftar[], int jumlahData) {
    cout << "================================================================================" << endl;
    cout << "                     JADWAL & KETERSEDIAAN LAPANGAN HARI INI                    " << endl;
    cout << "================================================================================" << endl;
    cout << left << setw(16) << "WAKTU"
         << setw(22) << "| LAPANGAN 1"
         << setw(22) << "| LAPANGAN 2"
         << setw(22) << "| LAPANGAN 3" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for (int jam = JAM_BUKA; jam < JAM_TUTUP; jam++) {
        string teksJam = (jam < 10 ? "0" : "") + to_string(jam) + ":00 - " +
                         (jam + 1 < 10 ? "0" : "") + to_string(jam + 1) + ":00";

        cout << left << setw(16) << teksJam;

        for (int lap = 1; lap <= JUMLAH_LAPANGAN; lap++) {
            int idx = cariIndexSlot(daftar, jumlahData, lap, jam);

            if (idx == -1) {
                cout << left << setw(22) << "| KOSONG";
            } else {
                // Ruang kolom lebih lega karena tanpa kode booking (maksimal 18 karakter)
                string namaTampil = daftar[idx].namaPemesan;
                if (namaTampil.length() > 18) {
                    namaTampil = namaTampil.substr(0, 17) + ".";
                }
                string status = "| " + namaTampil;
                cout << left << setw(22) << status;
            }
        }
        cout << endl;
    }
    cout << "================================================================================" << endl;

    if (jumlahData > 0) {
        cout << "\n--- RINCIAN RESERVASI AKTIF (" << jumlahData << " Transaksi) ---" << endl;
        for (int i = 0; i < jumlahData; i++) {
            cout << i + 1 << ". "
                 << daftar[i].namaPemesan
                 << " | Lapangan " << daftar[i].nomorLapangan
                 << " | Pukul " << daftar[i].jamMulai << ":00 - " << (daftar[i].jamMulai + daftar[i].durasi) << ":00"
                 << " | Rp " << daftar[i].totalBiaya << endl;
        }
    } else {
        cout << "[INFO] Belum ada reservasi yang masuk hari ini." << endl;
    }
}

void buatReservasi(Reservasi daftar[], int &jumlahData) {
    cout << "--- BUAT RESERVASI BARU ---" << endl;

    if (jumlahData >= MAX_RESERVASI) {
        cout << "[!] Maaf, kapasitas penyimpanan reservasi hari ini sudah penuh." << endl;
        return;
    }

    Reservasi baru;

    do {
        cout << "Nama Pemesan / Tim : ";
        getline(cin, baru.namaPemesan);
        if (baru.namaPemesan.empty()) {
            cout << "[!] Nama pemesan tidak boleh kosong." << endl;
        }
    } while (baru.namaPemesan.empty());

    while (true) {
        baru.nomorLapangan = inputAngka("Pilih Lapangan (1-3): ");
        if (baru.nomorLapangan >= 1 && baru.nomorLapangan <= JUMLAH_LAPANGAN) {
            break;
        }
        cout << "[!] Lapangan hanya tersedia nomor 1 sampai " << JUMLAH_LAPANGAN << "." << endl;
    }

    while (true) {
        baru.jamMulai = inputAngka("Jam Mulai (9 - 22)  : ");
        if (baru.jamMulai >= JAM_BUKA && baru.jamMulai < JAM_TUTUP) {
            break;
        }
        cout << "[!] Jam operasional mulai pukul " << JAM_BUKA << ":00 hingga maksimal mulai pukul " << JAM_TUTUP - 1 << ":00." << endl;
    }

    while (true) {
        baru.durasi = inputAngka("Durasi Sewa (jam)   : ");
        if (baru.durasi < 1) {
            cout << "[!] Durasi minimal adalah 1 jam." << endl;
        } else if (baru.jamMulai + baru.durasi > JAM_TUTUP) {
            int maksDurasi = JAM_TUTUP - baru.jamMulai;
            cout << "[!] Melewati jam tutup (" << JAM_TUTUP << ":00). Maksimal durasi di jam ini adalah " << maksDurasi << " jam." << endl;
        } else {
            break;
        }
    }

    if (cekBentrok(daftar, jumlahData, baru.nomorLapangan, baru.jamMulai, baru.durasi)) {
        cout << "\n[GAGAL] Jadwal bentrok! Lapangan " << baru.nomorLapangan
             << " sudah dipesan pada rentang pukul " << baru.jamMulai << ":00 - "
             << (baru.jamMulai + baru.durasi) << ":00." << endl;
        return;
    }

    baru.totalBiaya = baru.durasi * HARGA_PER_JAM;

    daftar[jumlahData] = baru;
    jumlahData++;

    cout << "\n==========================================" << endl;
    cout << "          RESERVASI BERHASIL!             " << endl;
    cout << "==========================================" << endl;
    cout << "Nama Pemesan : " << baru.namaPemesan << endl;
    cout << "Lapangan     : Lapangan " << baru.nomorLapangan << endl;
    cout << "Waktu Main   : " << baru.jamMulai << ":00 - " << (baru.jamMulai + baru.durasi) << ":00 (" << baru.durasi << " jam)" << endl;
    cout << "Total Biaya  : Rp " << baru.totalBiaya << endl;
    cout << "==========================================" << endl;
}

// Placeholder sementara (Tahap 4)
void cariPemesan(const Reservasi daftar[], int jumlahData) {
    cout << "[INFO] Fitur Cari Pemesan siap dibangun di Tahap 4." << endl;
}

void batalkanReservasi(Reservasi daftar[], int &jumlahData) {
    cout << "[INFO] Fitur Batalkan Reservasi siap dibangun di Tahap 4." << endl;
}