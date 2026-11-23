#include <iostream>

using namespace std;

int main(){
    int tb;
    int bb;

    cout <<"Masukkan Tinggi Badan : "; cin >> tb;
    cout <<"Masukkan Berat Badan : "; cin >> bb;

    if (tb - bb < 100){
        cout << "Anda Kegemukan, Diet laa";
    }else if(tb - bb >= 100, tb - bb <= 110){
        cout << "Ideal deh";
    }else if(tb - bb >= 110 , tb - bb <= 120){
        cout << "Kurus, Makannnnn";
    }else if(tb - bb >= 130){
        cout << "Sangat Kurus";
    }
}