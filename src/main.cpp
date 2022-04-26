#include <iostream>
#include "include/rectangle.hpp"

using namespace std;

int main()
{
    persegiPanjang pP1(4,4,6,4), pP2(8,7,6,4),pP3(6,5,8,4), pP4(15,7,6,4), pP5, pP6;

    cout << "\nDimensi persegi panjang yang digunakan adalah sebagai berikut :" << endl;
    cout << "Persegi panjang 1 = " << endl;
    pP1.print();
    cout << "Persegi panjang 2 = " << endl;
    pP2.print();
    cout << "Persegi panjang 3 = " << endl;
    pP3.print();
    cout << "Persegi panjang 4 = " << endl;
    pP4.print();


    pP5 = pP1 + pP2;
    cout << "Menjumlahkan persegi panjang 1 dan persegi panjang 2: " << endl;
    pP5.print();

    pP6 = pP1 - pP2;
    cout << "Mengurangi persegi panjang 1 dan persegi panjang 2: " << endl;
    pP6.print();

    pP1++;
    cout << "Menjadikan luasan persegi panjang 1 menjadi 2x nya : " << endl;
    pP1.print();

    pP2--;
    cout << "Menjadikan luasan persegi panjang 2 menjadi 0,5x nya : " << endl;
    pP2.print(); 
    
    cout << "Memeriksa apakah kedua persegi panjang saling beririsan (persegi panjang 1 dan 2) : " << endl;
    if (pP1 == pP2){
        cout << "ya! mereka beririsan!" << endl;
    }else {
        cout << "tidak, mereka tidak beririsan!" << endl;
    }

    cout << "\nMemeriksa apakah kedua persegi panjang tidak saling beririsan (persegi panjang 3 dan 4) :" << endl;
    if (pP3 == pP4){
        cout << "ya! mereka beririsan!" << endl;
    }else {
        cout << "tidak, mereka tidak beririsan!" << endl;
    }
    return 0;
}
