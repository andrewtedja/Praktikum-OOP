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

// latihan 2
template <class T>
void PrintArray(T arr[], int N)
{
    if (N == 0 || arr == nullptr)
    {
        cout << "Array kosong\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            cout << arr[i] << "]" << endl;
        }
        else
        {
            cout << arr[i] << ", ";
        }
    }
}

int main()
{
    int intArr[] = {5, 2, 8, 1, 3};
    double realArr[] = {2.5, 1.2, 3.8, 0.9, 4.1};
    int zeroArr[] = {};
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    // latihan 1 (minArray)
    cout << "minArray with integer element input: " << minArray(intArr, 5) << "\n";
    cout << "minArray with real element input: " << minArray(realArr, 5) << "\n\n";
    cout << "Apakah mungkin MinArray digunakan untuk data bertype Jam? (HH:MM:SS) " << endl;
    cout << "> Ya, dapat digunakan untuk tipe Jam dengan operator overloading (<)\n\n";

    // Latihan 2 (PrintArray)
    cout << "PrintArray (int):" << endl;
    PrintArray(intArr, 4);
    cout << "PrintArray (real):" << endl;
    PrintArray(realArr, 4);
    cout << "PrintArray (N=0):" << endl;
    PrintArray(zeroArr, 0);
    cout << "PrintArray (char):" << endl;
    PrintArray(charArr, 5);
    cout << endl;
    cout << "Bagaimana kalau yang ingin dicetak adalah Point?" << endl;
    cout << "> PrintAll dapat digunakan dengan operator overloading (<<) untuk tipe Point sehingga cout dapat menampilkan Point dengan format sesuai" << endl;

    return 0;
}
