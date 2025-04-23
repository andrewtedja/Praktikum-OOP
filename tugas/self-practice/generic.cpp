#include <iostream>
using namespace std;

template <class T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << add(5.5, 7.23) << endl;

    cin.get();
}