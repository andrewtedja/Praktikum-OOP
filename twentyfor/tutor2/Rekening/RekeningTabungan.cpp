#include "RekeningTabungan.h"

RekeningTabungan::RekeningTabungan(double saldo, double biaya) : Rekening(saldo)
{
    if (biaya < 0.0)
    {
        biaya = 0.0;
    }
    else
    {
        biayaTransaksi = biaya;
    }
};

void RekeningTabungan::setBiayaTransaksi(double newBiaya)
{
    biayaTransaksi = newBiaya;
}

double RekeningTabungan::getBiayaTransaksi() const
{
    return biayaTransaksi;
}

void RekeningTabungan::simpanUang(double uang)
{
    Rekening::simpanUang(uang);
    double saldo = getSaldo() - biayaTransaksi;
    setSaldo(saldo);
}

bool RekeningTabungan::tarikUang(double tarik)
{
    if (Rekening::tarikUang(tarik))
    {
        double saldo = getSaldo() - biayaTransaksi;
        if (saldo < biayaTransaksi)
        {
            return false;
        }
        else
        {
            setSaldo(getSaldo() - biayaTransaksi);
            return true;
        }
    }
    return false;
}