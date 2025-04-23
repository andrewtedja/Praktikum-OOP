#include <iostream>
using namespace std;

class VectorIndexOutOfBoundsException
{
private:
    int idxAccessed;
    int size;

public:
    VectorIndexOutOfBoundsException(int idxAccessed, int size)
    {
        this->idxAccessed = idxAccessed;
        this->size = size;
    }

    void printMessage()
    {
        cout << "Error: you are trying to access index " << idxAccessed << " in a vector of size " << size << endl;
    }

    T &operator[](int idx)
    {
        if (idx < 0 || idx >= size)
        {
            throw VectorIndexOutOfBoundsException(idx, size);
        }
        return this->
    }
};
