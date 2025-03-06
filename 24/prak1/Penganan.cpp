#include "Penganan.hpp"
#include <iostream>
using namespace std;

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

Penganan::Penganan() : keik(0), panekuk(0) {}

Penganan::Penganan(int keik, int panekuk) : keik(keik), panekuk(panekuk) {}

int Penganan::GetKeik() const
{
    return this->keik;
}

int Penganan::GetPanekuk() const
{
    return this->panekuk;
}
void Penganan::SetKeik(int)
{
    this->keik = keik;
}

void Penganan::SetPanekuk(int)
{
    this->panekuk = panekuk;
}

// ! operator overloading
// * operator+
Penganan operator+(const Penganan &a, const Penganan &b)
{
    int temp_keik = a.GetKeik() + b.GetKeik();
    int temp_panekuk = a.GetPanekuk() + b.GetPanekuk();
    Penganan temp(temp_keik, temp_panekuk);
    Penganan::n_rumah++;
    return temp;
};
