#include <iostream>
using namespace std;

template <class T>
void func(T t1, T t2)
{
    cout << "Masukan Anda: " << t1 << " dan " << t2 << ", memiliki tipe yang sama" << endl;
}

template <class T1, class T2>
void func(T1 t1, T2 t2)
{
    cout << "Masukan Anda: " << t1 << " dan " << t2 << ", mungkin memiliki tipe yang berbeda" << endl;
}

template <>
void func(char T1, int T2)
{
    for (int i = 0; i < T2; i++)
    {
        cout << T1 << endl;
    }
}

// int main()
// {
//     int a = 1;
//     int b = 2;
//     double c = 3.0;
//     double d = 4.0;
//     char e = 'x';
//     int f = 5;

//     func(a, b);
//     func(c, d);
//     func(a, c);
//     func(e, f);
//     return 0;
// }