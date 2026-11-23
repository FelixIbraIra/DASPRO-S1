#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    for(int i = 1; i<6; i++){
        for(int j = 1; j < 6 - i; j++ ){
            cout << " ";
        }
        for(int k = 1; k < i; k++){
            cout << "#";
        }
        cout << endl;
    }
}

/*PSEUDO CODE
FOR ( I <- 1 DAN I < N DAN I++)
    FOR (J <- 1 DAN J < N - I DAN J++)
        CETAK SPASI
    FOR (K <- 1 DAN K < I DAN K++)
        CETAK PAGAR
    CETAK ENTER
*/