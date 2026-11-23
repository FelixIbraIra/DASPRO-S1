#include <iostream> 
using namespace std;

int main(){
    string nama = "Felix";
    int usia = 17;
    float tb = 169.66;
    bool menikah = true;
    string status = menikah ? "Sudah Menikah" : "Belum Menikah";


    cout << "Namaku : " << nama << endl;
    cout << "Usiaku : " << usia << endl ;
    cout << "Tinggi Badan : " << tb << endl ;
    cout << "Statusku : " << status << endl ;
 
    int nilai_UTS;
    int nilai_UAS;
    float nilai_Tugas;
    float hasil;
    

    cout << "Masukkan Nilai UTS : ";
    cin >> nilai_UTS  ;
    cout << "Masukkan Nilai UAS : ";
    cin >> nilai_UAS;
    cout << "Masukkan Nilai Tugas : ";
    cin >> nilai_Tugas;
    cout << "Hasil Nilai Anda : " << (nilai_UTS * 30/100) + (nilai_UAS * 40/100) + (nilai_Tugas * 30/100) ;

    

    

}