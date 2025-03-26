#include <iostream>
using namespace std;

// latihan 1
template <class T>
T minArray(T arr[], int N)
{
    T minElmt = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (arr[i] < minElmt)
        {
            minElmt = arr[i];
        }
    }
    return minElmt;
}

class Jam
{
private:
    int hh, mm, ss;

public:
    Jam(int h = 0, int m = 0, int s = 0) : hh(h), mm(m), ss(s) {}

    bool operator<(const Jam &other) const
    {
        if (hh != other.hh)
        {
            if (hh < other.hh)
            {
                return true;
            }
        }
        if (mm != other.mm)
        {
            if (mm < other.mm)
            {
                return true;
            }
        }
        if (ss < other.ss)
        {
            return true;
        }
    }

    friend ostream &operator<<(ostream &os, const Clock &c)
    {
        os << (c.hh < 10 ? "0" : "") << c.hh << ":"
           << (c.mm < 10 ? "0" : "") << c.mm << ":"
           << (c.ss < 10 ? "0" : "") << c.ss;
        return os;
    }
};