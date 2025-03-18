#include "Rekening.h"

Rekening::Rekening(double saldo)
{
    if (saldo < 0)
    {
        this->saldo = 0.0;
    }
    else
    {
        this->saldo = saldo;
    }
}

void Rekening::setSaldo(double saldo)
{
    this->saldo = saldo;
}

double Rekening::getSaldo() const
{
    return saldo;
}

void Rekening::simpanUang(double newSaldo)
{
    saldo += newSaldo;
}

bool Rekening::tarikUang(double tarik)
{
    if ((saldo - tarik) >= 0.0)
    {
        saldo -= tarik;
        return true;
    }
    return false;
}