#include <iostream>
#include "kendaraan.hpp"

using namespace std;

int main()
{
    Bus bus1;
    Bus bus2(1001, "Mercedes", 2020, 10);
    MiniBus minibus1(2001, "Toyota", 2021);
    Mobil mobil1;
    Mobil mobil2(3001, "Honda", 2022, "Andi");

    cout << "Info Bus1:" << endl;
    bus1.printInfo();
    cout << "\nInfo Bus2:" << endl;
    bus2.printInfo();
    cout << "\nInfo MiniBus1:" << endl;
    minibus1.printInfo();
    cout << "\nInfo Mobil1:" << endl;
    mobil1.printInfo();
    cout << "\nInfo Mobil2:" << endl;
    mobil2.printInfo();
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

    KoleksiKendaraan koleksi1;
    KoleksiKendaraan koleksi2 = koleksi1;

    koleksi2 << mobil1;
    koleksi2 << minibus1;
    koleksi2 << bus1;

    cout << "Daftar Kendaraan 2:\n";
    koleksi2.printAll();

    KoleksiKendaraan koleksi3;
    koleksi3 = koleksi2;

    cout << "Daftar Kendaraan 3:\n";
    koleksi3.printAll();

    return 0;
}
