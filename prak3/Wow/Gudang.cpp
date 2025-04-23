#include <bits/stdc++.h>
#include "Barang.hpp"
#include "Gudang.hpp"
#include "Exception.hpp"
#include "BarangMakanan.hpp"
#include "BarangElektronik.hpp"
#include <exception>
using namespace std;

Gudang::Gudang()
{
    this->kapasitasTotal = DEFAULT_KAPASITAS;
    this->kapasitasTerpakai = 0;
    this->tenagaKerja = DEFAULT_TENAGA_KERJA;
    this->uang = DEFAULT_UANG;
};
Gudang::Gudang(int kapasitas, int uang, int tenagaKerja)
{
    this->kapasitasTotal = kapasitas;
    this->kapasitasTerpakai = 0;
    this->tenagaKerja = tenagaKerja;
    this->uang = uang;
}

Gudang::~Gudang() {

};

void Gudang::simpanBarang(Barang *barang)
{
    if (barang->getJenis() == "Makanan")
    {
        BarangMakanan *m = dynamic_cast<BarangMakanan *>(barang);
        try
        {
            if (m->getHariKedaluwarsa() <= 0)
            {
                throw BarangKedaluwarsaException();
            }
            pakaiKapasitas(barang->getBerat());
            pakaiUang(100);
            pakaiTenagaKerja();

            daftarBarang.push_back(barang);
            cout << "Barang [" << daftarBarang.size() - 1 << "] " << barang->getNama() << " berhasil disimpan" << endl;
        }
        catch (const BarangKedaluwarsaException &e)
        {
            cout << e.what() << ", buang dulu." << endl;
        }
        catch (const KapasitasPenuhException &e)
        {
            cout << e.what() << ", perluas gudang dulu." << endl;
        }
        catch (const UangTidakCukupException &e)
        {
            kapasitasTerpakai -= barang->getBerat();
            cout << e.what() << ", cari pemasukan dulu." << endl;
        }
        catch (const TenagaKerjaTidakCukupException &e)
        {
            kapasitasTerpakai -= barang->getBerat();

            tambahUang(100);
            cout << e.what() << ", rekrut dulu." << endl;
        }
    }
    else
    {
        BarangElektronik *e = dynamic_cast<BarangElektronik *>(barang);
        try
        {
            pakaiKapasitas(barang->getBerat());
            pakaiUang(100);
            pakaiTenagaKerja();

            daftarBarang.push_back(barang);
            cout << "Barang [" << daftarBarang.size() - 1 << "] " << barang->getNama() << " berhasil disimpan" << endl;
        }
        catch (const KapasitasPenuhException &e)
        {
            cout << e.what() << ", perluas gudang dulu." << endl;
        }
        catch (const UangTidakCukupException &e)
        {
            kapasitasTerpakai -= barang->getBerat();
            cout << e.what() << ", cari pemasukan dulu." << endl;
        }
        catch (const TenagaKerjaTidakCukupException &e)
        {
            kapasitasTerpakai -= barang->getBerat();
            tambahUang(100);
            cout << e.what() << ", rekrut dulu." << endl;
        }
    }
}

void Gudang::tambahKapasitas(int kg)
{
    this->kapasitasTotal += kg;
}

void Gudang::tambahTenagaKerja(int jumlah)
{
    this->tenagaKerja += jumlah;
}

void Gudang::tambahUang(int jumlah)
{
    this->uang += jumlah;
}

void Gudang::pakaiKapasitas(int kg)
{
    if (this->kapasitasTerpakai + kg >= this->kapasitasTotal)
    {
        throw KapasitasPenuhException();
    }
    this->kapasitasTerpakai += kg;
}

void Gudang::pakaiUang(int jumlah)
{
    if (this->uang - jumlah < 0)
    {
        throw UangTidakCukupException();
    }
    this->uang -= jumlah;
}

void Gudang::pakaiTenagaKerja()
{
    if (this->tenagaKerja < 1)
    {
        throw TenagaKerjaTidakCukupException();
    }
    tenagaKerja--;
}

void Gudang::sebutBarang(int idx)
{
    try
    {
        Barang *barang = daftarBarang.at(idx);
        cout << barang->getNama() << " - "
             << barang->getJenis() << " - "
             << barang->getBerat() << "kg" << endl;
    }
    catch (const std::out_of_range &e)
    {
        cout << e.what() << endl;
    }
}

void Gudang::statusGudang() const
{
    cout << "Status gudang:\n";
    cout << "  Kapasitas total: " << kapasitasTotal << " kg\n";
    cout << "  Kapasitas terpakai: " << kapasitasTerpakai << " kg\n";
    cout << "  Uang: " << uang << "\n";
    cout << "  Tenaga kerja: " << tenagaKerja << "\n";
    cout << "  Barang:\n";

    for (int i = 0; i < daftarBarang.size(); i++)
    {
        cout << "    [" << i << "] " << daftarBarang[i]->getNama() << " - " << daftarBarang[i]->getJenis() << " - " << daftarBarang[i]->getBerat() << "kg" << endl;
    }
}
