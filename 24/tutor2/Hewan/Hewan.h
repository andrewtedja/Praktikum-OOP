#ifndef HEWAN_H
#define HEWAN_H
#include <iostream>
#include <string>
using namespace std;

class Hewan
{
protected:
    string nama;

public:
    // ctor
    Hewan(string nama) : nama(nama) {};
    ~Hewan()
    {
        cout << "Hewan mati " << nama << endl;
    };

    virtual void print()
    {
        cout << "Hewan ini namanya " << nama << endl;
    };
};

class Anjing : public Hewan
{
public:
    Anjing(string nama) : Hewan(nama) {};
    virtual void print() override
    {
        cout << "Anjing ini namanya " << nama << endl;
    };
    ~Anjing()
    {
        cout << "Anjing mati " << nama << endl;
    };
};

class Kucing : public Hewan
{
public:
    Kucing(string nama) : Hewan(nama) {};
    virtual void print() override
    {
        cout << "Kucing ini namanya " << nama << endl;
    };
    ~Kucing()
    {
        cout << "Kucing mati " << nama << endl;
    };
};

class KucingAnggora : public Kucing
{
protected:
    string pemilik;

public:
    KucingAnggora(string nama, string pemilik) : Kucing(nama), pemilik(pemilik) {};
    void print() override
    {
        cout << "Kucing anggora ini namanya " << nama << ". Pemiliknya adalah " << pemilik << endl;
    };
    ~KucingAnggora()
    {
        cout << "Kucing anggora mati " << nama << endl;
    };
};

class AnjingBulldog : public Anjing
{
protected:
    string pemilik;

public:
    AnjingBulldog(string nama, string pemilik) : Anjing(nama), pemilik(pemilik) {};
    void print() override
    {
        cout << "Anjing bulldog ini namanya" << nama << ". Pemiliknya adalah " << pemilik << endl;
    };
    ~AnjingBulldog()
    {
        cout << "Anjing bulldog mati" << nama << endl;
    };
};

#endif
