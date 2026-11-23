#include <iostream>

using namespace std;

struct Kartesian{
    double x;
    double y;
};

int main(){
    Kartesian k1;

    cout << "Masukkan nilai x : ";
    cin >> k1.x;   
    cout << "Masukkan nilai y : ";
    cin >> k1.y;
    
    cout << "\nTitik koordinat Kartesian : (" << k1.x << ", " << k1.y << ")" << endl;

    return 0;
}