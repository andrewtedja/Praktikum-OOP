#include "Goalkeeper.hpp"
#include <bits/stdc++.h>

Goalkeeper::Goalkeeper() : Footballer()
{
    this->cleanSheets = 0;
    this->saves = 0;
    this->totalShotsOnGoal = 0;
    this->playPosition = "goalkeeper";
}

Goalkeeper::Goalkeeper(string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal) : Footballer()
{
    this->name = name;
    this->birthYear = birthYear;
    this->cleanSheets = cleanSheets;
    this->saves = saves;
    this->totalShotsOnGoal = totalShotsOnGoal;
    this->playPosition = "goalkeeper";
}

int Goalkeeper::setCleanSheets(int n)
{
    this->cleanSheets = n;
    return n;
}

int Goalkeeper::getCleanSheets() const
{
    return this->cleanSheets;
}

int Goalkeeper::setSaves(int n)
{
    this->saves = n;
    return n;
}

int Goalkeeper::getSaves() const
{
    return this->saves;
}

int Goalkeeper::setTotalShotsOnGoal(int n)
{
    this->totalShotsOnGoal = n;
    return n;
}

int Goalkeeper::getTotalShotsOnGoal() const
{
    return this->totalShotsOnGoal;
}

float Goalkeeper::savePercentage()
{
    return (this->totalShotsOnGoal != 0) ? (static_cast<float>(this->saves) / this->totalShotsOnGoal * 100) : 0;
}

int Goalkeeper::transferRate()
{
    return (700000 * this->cleanSheets) + (50000 * this->saves);
}

void Goalkeeper::displayInfo()
{
    Footballer::displayInfo();
    cout << "Clean Sheets: " << this->cleanSheets << endl;
    cout << "Saves: " << this->saves << endl;
    cout << "Save Percentage: " << fixed << setprecision(2) << this->savePercentage() << "%" << endl;
}