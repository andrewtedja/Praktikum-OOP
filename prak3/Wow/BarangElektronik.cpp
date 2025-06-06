#include "BarangElektronik.hpp"
#include <iostream>
using namespace std;

BarangElektronik::BarangElektronik(string nama, int berat, int voltase) : Barang(nama, berat), voltase(voltase) {};

int BarangElektronik::getVoltase() const
{
    return voltase;
}

string BarangElektronik::getJenis() const
{
    return "Elektronik";
}