#include <iostream>
#include "Kompleks.hpp"
using namespace std;

Kompleks::Kompleks() : real(0), imag(0) {};

Kompleks::Kompleks(double r, double i) : real(r), imag(i) {};

Kompleks::Kompleks(const Kompleks &other)
{
    this->real = other.real;
    this->imag = other.imag;
}

double Kompleks::getReal() const
{
    return real;
}

double Kompleks::getImag() const
{
    return imag;
}

double Kompleks::setReal(double r)
{
    return this->real = r;
}

double Kompleks::setImag(double i)
{
    return this->imag = i;
}

Kompleks Kompleks::operator+(const Kompleks &other) const
{
    double tempReal = this->real + other.real;
    double tempImag = this->imag + other.imag;
    return Kompleks(tempReal, tempImag);
}

Kompleks Kompleks::operator-(const Kompleks &other) const
{
    double tempReal = this->real - other.real;
    double tempImag = this->imag - other.imag;

    return Kompleks(tempReal, tempImag);
}

Kompleks Kompleks::operator*(const Kompleks &other) const
{
    // double tempX = this->getReal() * other.real + imag * other.imag;
    // double tempY = this->getReal() * other.imag + imag * other.real;
    double tempX = this->real * other.real + this->imag * other.imag * -1;
    // cout<<this->imag;
    // cout<<other.imag;
    double tempY = this->real * other.imag + this->imag * other.real;
    return Kompleks(tempX, tempY);
}

bool Kompleks::operator==(const Kompleks &other) const
{
    if (this->real == other.real && this->imag == other.imag)
    {
        return true;
    }

    return false;
}

Kompleks &Kompleks::operator=(const Kompleks &other)
{
    if (this != &other)
    {
        this->imag = other.imag;
        this->real = other.real;
    }
    return *this;
}

ostream &operator<<(ostream &os, const Kompleks &c)
{
    if (c.imag == 0)
    {
        os << c.getReal();
    }
    else if (c.getImag() > 0)
    {
        os << c.getReal() << " + " << c.getImag() << "i";
    }
    else if (c.getImag() < 0)
    {
        os << c.getReal() << " - " << c.getImag() * -1 << "i";
    }
    return os;
}

// int main()
// {
//     // Kompleks a;
//     // cout << a;
//     // Kompleks c(3, 4);
//     // // cout << c.getReal();
//     // // cout << c.getImag();
//     // // cout << c;
//     // Kompleks b(3, 4);
//     // // cout << c+b;
//     // Kompleks a=b;
//     // cout << a;

//     Kompleks z(-1, 0);
//     // Kompleks c(3, 4);
//     // cout << c*b;
//     z.setImag(-3);
//     cout << z;
// };
