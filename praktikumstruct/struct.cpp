#include <iostream>

using namespace std;

int main(){
    int x = 87;
    int y;
    int *px;

    px = &x;
    y = *px;

    cout << " Alamat Memori x (&x)        = " << &x <<  endl;
    cout << " Isi variabel px (alamat x)  = " << px <<  endl;
    cout << " Nilai x Mula mula           = " << x <<  endl;
    cout << " Nilai yang ditunjuk (*px)   = " << *px <<  endl;
    cout << " Nilai y                     = " << y <<  endl;

    *px = 100;
    cout << "\nSetelah eksekusi :  *px = 100 " << endl;
    cout << "Isi variabel x sekarang  = " << x << endl;

    return 0;
}