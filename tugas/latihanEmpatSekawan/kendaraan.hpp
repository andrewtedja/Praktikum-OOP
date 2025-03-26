#ifndef __KENDARAAN_HPP__
#define __KENDARAAN_HPP__
#include <string>

// ! SOAL NO 1
class Kendaraan
{
protected:
    int nomor;
    std::string merk;
    int tahunKeluaran;

public:
    // * Ctors, CCtor, CAssign, Dtor
    Kendaraan();
    Kendaraan(int nomor, std::string merk, int tahunKeluaran);
    Kendaraan(const Kendaraan &other);
    Kendaraan &operator=(const Kendaraan &other);
    virtual ~Kendaraan();

    // * Method and Operator
    virtual void printInfo() const;
    virtual int biayaSewa(int lamaSewa) const = 0; // pure virtual -> abstrak base class
};

class Bus : public Kendaraan
{
private:
    int kapasitas;

public:
    Bus();
    Bus(int nomor, std::string merk, int tahunKeluaran, int kapasitas);
    void printInfo() const override;
    int biayaSewa(int lamaSewa) const override;
};

class MiniBus : public Kendaraan
{
public:
    MiniBus();
    MiniBus(int nomor, std::string merk, int tahunKeluaran);
    void printInfo() const override;
    int biayaSewa(int lamaSewa) const override;
    int diskon(int lamaSewa);
};

class Mobil : public Kendaraan
{
private:
    std::string supir = "XXXX";

public:
    Mobil();
    Mobil(int nomor, std::string merk, int tahunKeluaran, std::string supir);
    void printInfo() const override;
    int biayaSewa(int lamaSewa) const override;
};

// ! SOAL NO 2
class KoleksiKendaraan
{
private:
    int size;
    int Neff;
    Kendaraan **listKendaraan;

public:
    // * Ctors, CCtor, Dtor
    KoleksiKendaraan();
    KoleksiKendaraan(int size);
    KoleksiKendaraan(const KoleksiKendaraan &other);
    ~KoleksiKendaraan();

    // * Method and Operator
    void printAll() const;
    KoleksiKendaraan &operator=(const KoleksiKendaraan &other);
    KoleksiKendaraan &operator<<(Kendaraan &kendaraan);
    KoleksiKendaraan &operator<<(const KoleksiKendaraan &other);
};

#endif
