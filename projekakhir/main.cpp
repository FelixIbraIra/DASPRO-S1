#include <iostream>
#include <string>
#include <limits> // Untuk membersihkan buffer input jika user salah ketik

using namespace std;

// ==========================================
// 1. KONSTANTA ATURAN BISNIS
// ==========================================
const int MAX_RESERVASI = 100;      // Kapasitas maksimal array statis
const int JUMLAH_LAPANGAN = 3;      // 3 lapangan standar
const int JAM_BUKA = 9;             // Buka jam 09:00
const int JAM_TUTUP = 23;           // Tutup jam 23:00
const int HARGA_PER_JAM = 120000;   // Tarif flat Rp 120.000/jam

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
    int jamSelesai() const {
        return jamMulai + durasi;
    }
};

//kelompok terdebes

// jiass
// ==========================================
// 3. DEKLARASI FUNGSI (PROTOTYPE)
// ==========================================
void tampilkanMenu();
void lihatJadwal(const Reservasi daftar[], int jumlahData);
void buatReservasi(Reservasi daftar[], int &jumlahData, int &counterKode);
void cariPemesan(const Reservasi daftar[], int jumlahData);
void batalkanReservasi(Reservasi daftar[], int &jumlahData);

// ==========================================
// 4. FUNGSI UTAMA (MAIN)
// ==========================================
int main() {
    // Array statis untuk menyimpan seluruh data reservasi
    Reservasi daftarReservasi[MAX_RESERVASI];
    
    int jumlahData = 0;     // Menghitung berapa banyak slot array yang sudah terisi
    int counterKode = 1;    // Penghitung otomatis untuk kode B001, B002, dst.
    int pilihan;

    do {
        tampilkanMenu();
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        // Validasi jika user tidak sengaja memasukkan huruf saat diminta angka
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilihan = 0;
        }

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
// 5. IMPLEMENTASI FUNGSI
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

// Placeholder sementara (akan kita isi di Tahap 2 - 4)
void lihatJadwal(const Reservasi daftar[], int jumlahData) {
    cout << "[INFO] Fitur Lihat Jadwal siap dibangun di Tahap 3." << endl;
}

void buatReservasi(Reservasi daftar[], int &jumlahData, int &counterKode) {
    cout << "[INFO] Fitur Buat Reservasi siap dibangun di Tahap 2." << endl;
}

void cariPemesan(const Reservasi daftar[], int jumlahData) {
    cout << "[INFO] Fitur Cari Pemesan siap dibangun di Tahap 4." << endl;
}

void batalkanReservasi(Reservasi daftar[], int &jumlahData) {
    cout << "[INFO] Fitur Batalkan Reservasi siap dibangun di Tahap 4." << endl;
}