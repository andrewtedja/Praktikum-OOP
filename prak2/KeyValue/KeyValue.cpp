#include <iostream>
using namespace std;
#include <math.h>

template <typename k, typename v>
class KeyValue
{
private:
    k keys[10];
    v values[10];
    int NEff;

public:
    KeyValue()
    {
        this->NEff = 0;
    }

    KeyValue(const KeyValue &other)
    {
        this->NEff = other.NEff;
        for (int i = 0; i < NEff; i++)
        {
            this->keys[i] = other.keys[i];
            this->values[i] = other.values[i];
        }
    }

    void set(k key, v value)
    {
        if (NEff >= 10)
        {
            cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            return;
        }
        for (int i = 0; i < NEff; i++)
        {
            if (key == keys[i])
            {
                values[i] = value;
                return;
            }
        }
        keys[NEff] = key;
        values[NEff] = value;
        NEff++;
    }

    void display(k key)
    {
        for (int i = 0; i < NEff; i++)
        {
            if (key == keys[i])
            {
                cout << values[i] << endl;
                return;
            }
        }
        cout << "Key tidak ditemukan!" << endl;
    }

    ~KeyValue() {};
};

template <typename v>
class KeyValue<double, v>
{
private:
    double keys[10];
    v values[10];
    int NEff;

public:
    KeyValue()
    {
        this->NEff = 0;
    }

    KeyValue(const KeyValue &other)
    {
        this->NEff = other.NEff;
        for (int i = 0; i < NEff; i++)
        {
            this->keys[i] = other.keys[i];
            this->values[i] = other.values[i];
        }
    }

    void set(double key, v value)
    {
        if (NEff >= 10)
        {
            cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            return;
        }
        for (int i = 0; i < NEff; i++)
        {
            if (key == keys[i] || abs(key - keys[i]) < 0.01)
            {
                values[i] = value;
                return;
            }
        }
        keys[NEff] = key;
        values[NEff] = value;
        NEff++;
    }

    void display(double key)
    {
        for (int i = 0; i < NEff; i++)
        {
            if (key == keys[i] || abs(key - keys[i]) < 0.01)
            {
                cout << values[i] << endl;
                return;
            }
        }
        cout << "Key tidak ditemukan!" << endl;
    }

    ~KeyValue() {};
};

// int main()
// {
//     KeyValue<int, string> kv;
//     kv.set(1, "Alice");
//     kv.set(2, "Bob");
//     kv.set(3, "Charlie");
//     kv.display(1); // Output: "Alice"
//     kv.display(2); // Output: "Bob"
//     kv.display(3); // Output: "Charlie"
//     return 0;
// }