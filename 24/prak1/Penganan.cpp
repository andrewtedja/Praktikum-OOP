#include "Penganan.hpp"
#include <iostream>
using namespace std;

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

Penganan::Penganan()
{
    panekuk = 0;
    keik = 0;
}

Penganan::Penganan(int keik, int panekuk)
{
    this->keik = keik;
    this->panekuk = panekuk;
}

int Penganan::GetKeik() const
{
    return keik;
}

int Penganan::GetPanekuk() const
{
    return panekuk;
}

void Penganan::SetKeik(int newKeik)
{
    keik = newKeik;
}

void Penganan::SetPanekuk(int newPanekuk)
{
    panekuk = newPanekuk;
}
Penganan operator+(const Penganan &p1, const Penganan &p2)
{
    int tempKeik = p1.GetKeik() + p2.GetKeik();
    int tempPanekuk = p1.GetPanekuk() + p2.GetPanekuk();
    Penganan::n_rumah += 1;
    return Penganan(tempKeik, tempPanekuk);
}

Penganan operator-(const Penganan &p1, const Penganan &p2)
{
    int temp_beli_keik = (p1.GetKeik() - p2.GetKeik()) > 0 ? p2.GetKeik() : p1.GetKeik();
    int temp_beli_panekuk = (p1.GetPanekuk() - p2.GetPanekuk()) > 0 ? p2.GetPanekuk() : p1.GetPanekuk();
    Penganan::uang = temp_beli_keik * 51 + temp_beli_panekuk * 37;
    return Penganan(p1.GetKeik() - temp_beli_keik, p1.GetPanekuk() - temp_beli_panekuk);
}