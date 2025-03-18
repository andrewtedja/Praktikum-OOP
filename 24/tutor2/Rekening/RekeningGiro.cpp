#include "RekeningGiro.h"

RekeningGiro::RekeningGiro(double saldo, double bunga) : Rekening(saldo)
{
    sukuBunga = bunga;
};

void RekeningGiro::setSukuBunga(double newBunga)
{
    sukuBunga = newBunga;
}

double RekeningGiro::getSukuBunga() const
{
    return sukuBunga;
}

double RekeningGiro::hitungBunga()
{
    return getSaldo() * sukuBunga;
}