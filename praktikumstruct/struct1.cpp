#include <iostream>

using namespace std;

int main(){
    int z = 20, s = 30;
    int *pz, *ps;

    pz = &z;
    ps = &s;

    cout << "Nilai Awal : " << endl;
    cout << "z = " << z << " | s = " << s << endl;

    *pz += *ps;

    cout << "\nSetelah eksekusi : *pz += *ps " << endl;
    cout << "z = " << z << endl;
    cout << "s = " << s << endl;

    return 0;
}