#include <stdio.h>
#include <string.h>
#include "kendaraan.hpp"
#include <iostream>

// ! SOAL NO 1

// * Ctors, CCtor, CAssign, Dtor
Kendaraan::Kendaraan()
{
    nomor = 0;
    tahunKeluaran = 0;
    merk = "XXX";
}

Kendaraan::Kendaraan(int nomor, std::string merk, int tahunKeluaran)
{
    this->nomor = nomor;
    this->merk = merk;
    this->tahunKeluaran = tahunKeluaran;
}

Kendaraan::Kendaraan(const Kendaraan &other)
{
    this->nomor = other.nomor;
    this->merk = other.merk;
    this->tahunKeluaran = other.tahunKeluaran;
}

Kendaraan &Kendaraan::operator=(const Kendaraan &other)
{
    if (this != &other)
    {
        this->nomor = other.nomor;
        this->merk = other.merk;
        this->tahunKeluaran = other.tahunKeluaran;
    }
    return *this;
};

Kendaraan::~Kendaraan() {};

Bus::Bus() : Kendaraan()
{
    this->kapasitas = 0;
}
Bus::Bus(int nomor, std::string merk, int tahunKeluaran, int kapasitas)
    : Kendaraan(nomor, merk, tahunKeluaran), kapasitas(kapasitas) {};

MiniBus::MiniBus() : Kendaraan() {}
MiniBus::MiniBus(int nomor, std::string merk, int tahunKeluaran)
    : Kendaraan(nomor, merk, tahunKeluaran) {};

Mobil::Mobil() : Kendaraan()
{
    supir = "XXXX";
}
Mobil::Mobil(int nomor, std::string merk, int tahunKeluaran, std::string supir)
    : Kendaraan(nomor, merk, tahunKeluaran), supir(supir) {};

// * Methods

void Kendaraan::printInfo() const
{
    std::cout << "Nomor Kendaraan: " << nomor << std::endl;
    std::cout << "Merk: " << merk << std::endl;
    std::cout << "Tahun Keluaran: " << tahunKeluaran << std::endl;
}

void Bus::printInfo() const
{
    Kendaraan::printInfo();
    std::cout << "Kapasitas: " << kapasitas << std::endl;
}

void MiniBus::printInfo() const
{
    Kendaraan::printInfo();
}

void Mobil::printInfo() const
{
    Kendaraan::printInfo();
    std::cout << "Supir: " << supir << std::endl;
}

int Bus::biayaSewa(int lamaSewa) const
{
    return 1000000 * lamaSewa;
}

int MiniBus::biayaSewa(int lamaSewa) const
{
    int biaya = 0;
    if (lamaSewa <= 5)
    {
        biaya = 5000000;
    }
    else
    {
        biaya = 5000000 + 500000 * (lamaSewa - 5);
    }
    return biaya;
}

int MiniBus::diskon(int lamaSewa)
{
    int biaya = biayaSewa(lamaSewa);
    if (lamaSewa > 10)
    {
        return biaya * 0.1;
    };
    return 0;
}

int Mobil::biayaSewa(int lamaSewa) const
{
    return 500000 * lamaSewa;
}

// ! SOAL NO 2
// * Ctors, CCtor, CAssign, Dtors
KoleksiKendaraan::KoleksiKendaraan()
{
    size = 100;
    Neff = 0;
    listKendaraan = new Kendaraan *[size];
}

KoleksiKendaraan::KoleksiKendaraan(int size)
{
    this->size = size;
    Neff = 0;
    listKendaraan = new Kendaraan *[size];
}

KoleksiKendaraan::KoleksiKendaraan(const KoleksiKendaraan &other)
{
    this->size = other.size;
    this->Neff = other.Neff;
    this->listKendaraan = new Kendaraan *[size];
    for (int i = 0; i < other.Neff; i++)
    {
        listKendaraan[i] = other.listKendaraan[i];
    }
}

KoleksiKendaraan &KoleksiKendaraan::operator=(const KoleksiKendaraan &other)
{
    if (this != &other)
    {
        delete[] listKendaraan;
        this->size = other.size;
        this->Neff = other.Neff;
        listKendaraan = new Kendaraan *[size];
        for (int i = 0; i < other.Neff; i++)
        {
            listKendaraan[i] = other.listKendaraan[i];
        }
    }
    return *this;
}

KoleksiKendaraan::~KoleksiKendaraan()
{
    delete[] listKendaraan;
};

// * Method and Operator
void KoleksiKendaraan::printAll() const
{
    for (int i = 0; i < Neff; i++)
    {
        listKendaraan[i]->printInfo();
        std::cout << std::endl;
    }
}

KoleksiKendaraan &KoleksiKendaraan::operator<<(Kendaraan &kendaraan)
{
    listKendaraan[Neff++] = &kendaraan;
    return *this;
}

KoleksiKendaraan &KoleksiKendaraan::operator<<(const KoleksiKendaraan &other)
{
    for (int i = 0; i < other.Neff && Neff < size; i++)
    {
        listKendaraan[Neff++] = other.listKendaraan[i];
    }
    return *this;
};