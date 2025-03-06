#include "Weed.hpp"
#include <iostream>

Weed::Weed()
{
    many = 1;
}

Weed::Weed(int n)
{
    this->many = n;
}

Weed::Weed(const Weed &b)
{
    this->many = b.many;
}

Weed::~Weed() {};

void Weed::step()
{
    if (many >= 1 && many <= 1000)
    {
        for (int i = 0; i < many; i++)
        {
            std::cout << "kresek...";
        }
        std::cout << std::endl;
    }
}
