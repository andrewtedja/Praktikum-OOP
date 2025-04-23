#include <iostream>
#include "Barang.hpp"
using namespace std;

Barang::Barang(string nama, int berat) : nama(nama), berat(berat) {};

string Barang::getNama() const
{
    return nama;
}

int Barang::getBerat() const
{
    return berat;
}

Barang::~Barang() {};