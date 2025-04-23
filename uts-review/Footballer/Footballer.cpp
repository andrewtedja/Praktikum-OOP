#include <bits/stdc++.h>
#include "Footballer.hpp"
#include <math.h>
using namespace std;

Footballer::Footballer()
{
    this->name = "noname";
    this->birthYear = 2000;
    this->playPosition = "none";
    this->nationality = "Indonesia";
    this->height = 180;
    this->weight = 70;
}

Footballer::Footballer(string name, int birthYear, string playPosition, string nationality, int height, int weight)
{
    this->name = name;
    this->birthYear = birthYear;
    this->playPosition = playPosition;
    this->nationality = nationality;
    this->height = height;
    this->weight = weight;
}

Footballer::Footballer(const Footballer &other)
{
    this->name = other.name;
    this->birthYear = other.birthYear;
    this->playPosition = other.playPosition;
    this->nationality = other.nationality;
    this->height = other.height;
    this->weight = other.weight;
}

Footballer::~Footballer() {};

Footballer &Footballer::operator=(const Footballer &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->birthYear = other.birthYear;
        this->playPosition = other.playPosition;
        this->nationality = other.nationality;
        this->height = other.height;
        this->weight = other.weight;
    }
    return *this;
}

void Footballer::setName(string newName)
{
    name = newName;
}

string Footballer::getName()
{
    return name;
}

void Footballer::setPlayPosition(string newPlayPosition)
{
    playPosition = newPlayPosition;
}

string Footballer::getPlayPosition()
{
    return playPosition;
}

void Footballer::setNationality(string newNationality)
{
    nationality = newNationality;
}

string Footballer::getNationality()
{
    return nationality;
}

void Footballer::setHeight(int newHeight)
{
    height = newHeight;
}

int Footballer::getHeight()
{
    return height;
}

void Footballer::setWeight(int newWeight)
{
    weight = newWeight;
}

int Footballer::getWeight()
{
    return weight;
}

int Footballer::getAge()
{
    return CURRENT_YEAR - birthYear;
}

double Footballer::getBMI()
{
    double weight = (double)this->getWeight();
    double height = (double)this->getHeight() / 100;
    double bmi = weight / (height * height);
    return bmi;
}

// name -> nama
// endline
// 16 17 r nya di bmi and category TC
string Footballer::getCategory()
{
    string category;
    double bmi = this->getBMI();
    if (bmi < 18.5)
    {
        category = "Underweight";
    }
    else if (bmi >= 18.5 && bmi < 25.0)
    {
        category = "Normal";
    }
    else if (bmi >= 25.0 && bmi < 30.0)
    {
        category = "Overweight";
    }
    else if (bmi >= 30.0)
    {
        category = "Obese";
    };
    return category;
};

void Footballer::displayInfo()
{
    cout << "Name: " << this->getName() << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Position: " << this->getPlayPosition() << endl;
    cout << "Nationality: " << this->getNationality() << endl;
    cout << fixed << setprecision(2) << "BMI: " << this->getBMI() << " (" << this->getCategory() << ")\n";
    cout << "Transfer Rate: " << this->transferRate() << endl;
}

// int main()
// {
//     Footballer f("Andrew", 2005, "Midfield", "Indo", 175, 68);
//     f.displayInfo();
// }