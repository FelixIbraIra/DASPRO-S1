#include <iostream>

using namespace std;

int main(){
    float ipk;

    string nama;

    cout << "Masukkkan nama kau LEK : " ;
    cin >> nama;

    cout << "Masukkan IPK Kau LEK : ";
    cin >> ipk;

    if (ipk >= 3.5 ){
        cout << "Cumlaude kau LEK ";
    }else if(ipk > 3 ){
        cout << "Sikik aah";
    }else if(ipk > 2.5 ) {
        cout << "SINANGGAR TULO";
    }else{
        cout << "Tarutung";
    }
}