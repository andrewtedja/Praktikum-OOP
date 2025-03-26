#include <iostream>
#include "kendaraan.hpp"

using namespace std;

int main()
{
    Bus bus1(1001, "Mercedes", 2020, 10);

    MiniBus minibus1(2001, "Toyota", 2021);
    Mobil mobil1(3001, "Honda", 2022, "Andi");

    cout << "Info Bus1:" << endl;
    bus1.printInfo();

    cout << "\nInfo MiniBus1:" << endl;
    minibus1.printInfo();

    cout << "\nInfo Mobil1:" << endl;
    mobil1.printInfo();

    cout << "\nInfo Bus5:" << endl;

    cout << "\nInfo Mobil6:" << endl;
    Mobil mobil6 = mobil1;
    mobil6.printInfo();

    int lamaSewa[] = {3, 7, 11};

    for (int hari : lamaSewa)
    {
        cout << "\nLama sewa: " << hari << " hari" << endl;
        cout << "Biaya sewa bus: " << bus1.biayaSewa(hari) << endl;
        cout << "Biaya sewa minibus: " << minibus1.biayaSewa(hari) << endl;
        cout << "Biaya sewa mobil: " << mobil1.biayaSewa(hari) << endl;

        cout << "Diskon minibus: " << minibus1.biayaSewa(hari) - minibus1.diskon(hari) << endl;
    }
    cout << "\n==========================================================================\n";

    KoleksiKendaraan koleksi;

    koleksi << mobil1;
    koleksi << minibus1;
    koleksi << bus1;

    cout << "Daftar Kendaraan:\n";
    koleksi.printAll();

    return 0;
}
