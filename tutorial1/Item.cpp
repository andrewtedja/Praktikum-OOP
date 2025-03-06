#include "Item.hpp"

int Item::totalItems = 0;
int Item::totalRevenue = 0;

Item::Item() : serialNum(totalItems + 1)
{
    stock = 0;
    price = 0;
    sold = 0;
    totalItems++;
};

Item::Item(int stock, int price) : serialNum(totalItems + 1)
{
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    totalItems++;
}

Item::Item(const Item &i) : serialNum(totalItems + 1)
{
    this->stock = i.stock;
    this->price = i.price;
    this->sold = i.sold;
    totalItems++;
}

Item::~Item() {};

int Item::getSerialNum() const
{
    return this->serialNum;
}

int Item::getSold() const
{
    return this->sold;
}

int Item::getPrice() const
{
    return this->price;
}

void Item::addStock(int addedStock)
{
    if (addedStock > 0)
    {
        this->stock += addedStock;
    }
}

void Item::sell(int soldStock)
{
    int itemSold;
    if (this->stock >= soldStock) // stok cukup
    {
        itemSold = soldStock;
    }
    else
    { // stop kurang daripada yang dijual
        itemSold = this->stock;
    }
    totalRevenue += itemSold * this->price;
    this->stock -= itemSold;
    this->sold += itemSold;
}

void Item::setPrice(int newPrice)
{
    this->price = newPrice;
}