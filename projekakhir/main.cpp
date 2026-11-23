#include <iostream>
#include <string>
#include <limits>

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
    string kodeBooking;
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
int inputAngka(string pesan);                                                                   // [BARU DI TAHAP 2]                                                          // [BARU DI TAHAP 2]
bool cekBentrok(const Reservasi daftar[], int jumlahData, int lapangan, int jamMulai, int durasi); // [BARU DI TAHAP 2]

void lihatJadwal(const Reservasi daftar[], int jumlahData);
void buatReservasi(Reservasi daftar[], int &jumlahData, int &counterKode);
void cariPemesan(const Reservasi daftar[], int jumlahData);
void batalkanReservasi(Reservasi daftar[], int &jumlahData);

// ==========================================
// 4. FUNGSI UTAMA (MAIN)
// ==========================================
int main() {
    Reservasi daftarReservasi[MAX_RESERVASI];
    int jumlahData = 0;
    int counterKode = 1;
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
                buatReservasi(daftarReservasi, jumlahData, counterKode);
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
// 5. IMPLEMENTASI FUNGSI BANTU [BARU DI TAHAP 2]
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
            // Membersihkan sisa karakter 'Enter' di buffer agar aman untuk getline() berikutnya
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nilai;
        }
    }
}


bool cekBentrok(const Reservasi daftar[], int jumlahData, int lapangan, int jamMulai, int durasi) {
    int jamSelesaiBaru = jamMulai + durasi;

    // Telusuri semua reservasi yang sudah tersimpan di array
    for (int i = 0; i < jumlahData; i++) {
        // Cek hanya jika nomor lapangannya sama
        if (daftar[i].nomorLapangan == lapangan) {
            int jamMulaiLama = daftar[i].jamMulai;
            int jamSelesaiLama = daftar[i].jamMulai + daftar[i].durasi;

            // Rumus irisan rentang waktu (Interval Overlap)
            if (jamMulai < jamSelesaiLama && jamSelesaiBaru > jamMulaiLama) {
                return true; // Bentrok terdeteksi!
            }
        }
    }
    return false; // Jadwal aman
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

// [BARU DI TAHAP 2] Implementasi Menu 2
void buatReservasi(Reservasi daftar[], int &jumlahData, int &counterKode) {
    cout << "--- BUAT RESERVASI BARU ---" << endl;

    // 1. Cek kapasitas array statis
    if (jumlahData >= MAX_RESERVASI) {
        cout << "[!] Maaf, kapasitas penyimpanan reservasi hari ini sudah penuh." << endl;
        return;
    }

    Reservasi baru;

    // 2. Input nama pemesan (bisa mengandung spasi, misal: "Garuda FC")
    do {
        cout << "Nama Pemesan / Tim : ";
        getline(cin, baru.namaPemesan);
        if (baru.namaPemesan.empty()) {
            cout << "[!] Nama pemesan tidak boleh kosong." << endl;
        }
    } while (baru.namaPemesan.empty());

    // 3. Input & validasi nomor lapangan (1 - 3)
    while (true) {
        baru.nomorLapangan = inputAngka("Pilih Lapangan (1-3): ");
        if (baru.nomorLapangan >= 1 && baru.nomorLapangan <= JUMLAH_LAPANGAN) {
            break;
        }
        cout << "[!] Lapangan hanya tersedia nomor 1 sampai " << JUMLAH_LAPANGAN << "." << endl;
    }

    // 4. Input & validasi jam mulai (9 - 22)
    while (true) {
        baru.jamMulai = inputAngka("Jam Mulai (9 - 22)  : ");
        if (baru.jamMulai >= JAM_BUKA && baru.jamMulai < JAM_TUTUP) {
            break;
        }
        cout << "[!] Jam operasional mulai pukul " << JAM_BUKA << ":00 hingga maksimal mulai pukul " << JAM_TUTUP - 1 << ":00." << endl;
    }

    // 5. Input & validasi durasi agar tidak melewati jam tutup (23:00)
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

    // 6. Cek apakah jadwal bentrok dengan data di array
    if (cekBentrok(daftar, jumlahData, baru.nomorLapangan, baru.jamMulai, baru.durasi)) {
        cout << "\n[GAGAL] Jadwal bentrok! Lapangan " << baru.nomorLapangan
             << " sudah dipesan pada rentang pukul " << baru.jamMulai << ":00 - "
             << (baru.jamMulai + baru.durasi) << ":00." << endl;
        return;
    }

    // 7. Hitung biaya, buat kode, dan simpan ke array
    baru.totalBiaya = baru.durasi * HARGA_PER_JAM;

    daftar[jumlahData] = baru;
    jumlahData++;
    counterKode++;

    // 8. Tampilkan struk konfirmasi
    cout << "\n==========================================" << endl;
    cout << "          RESERVASI BERHASIL!             " << endl;
    cout << "==========================================" << endl;
    cout << "Kode Booking : " << baru.kodeBooking << endl;
    cout << "Nama Pemesan : " << baru.namaPemesan << endl;
    cout << "Lapangan     : Lapangan " << baru.nomorLapangan << endl;
    cout << "Waktu Main   : " << baru.jamMulai << ":00 - " << (baru.jamMulai + baru.durasi) << ":00 (" << baru.durasi << " jam)" << endl;
    cout << "Total Biaya  : Rp " << baru.totalBiaya << endl;
    cout << "==========================================" << endl;
}

// Placeholder sementara (Tahap 3 & 4)
void lihatJadwal(const Reservasi daftar[], int jumlahData) {
    cout << "[INFO] Fitur Lihat Jadwal siap dibangun di Tahap 3." << endl;
}

void cariPemesan(const Reservasi daftar[], int jumlahData) {
    cout << "[INFO] Fitur Cari Pemesan siap dibangun di Tahap 4." << endl;
}

void batalkanReservasi(Reservasi daftar[], int &jumlahData) {
    cout << "[INFO] Fitur Batalkan Reservasi siap dibangun di Tahap 4." << endl;
}

//nabil tes