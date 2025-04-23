#include "Defender.hpp"
#include <bits/stdc++.h>

Defender::Defender() : Footballer()
{
    this->tackleSuccess = 0;
    this->interceptions = 0;
    this->playPosition = "defender";
}

Defender::Defender(string name, int birthYear, int tackleSuccess, int interceptions) : Footballer()
{
    this->name = name;
    this->tackleSuccess = tackleSuccess;
    this->interceptions = interceptions;
    this->playPosition = "defender";
    this->birthYear = birthYear;
}

int Defender::setTackleSuccess(int n)
{
    this->tackleSuccess = n;
    return n;
}

int Defender::getTackleSuccess() const
{
    return this->tackleSuccess;
}

int Defender::setInterceptions(int n)
{
    this->interceptions = n;
    return n;
}

int Defender::getInterceptions() const
{
    return this->interceptions;
}

int Defender::defensiveRating()
{
    return (this->tackleSuccess * 2) + this->interceptions;
}

int Defender::transferRate()
{
    return (600000 * this->tackleSuccess) + (400000 * this->interceptions);
}

void Defender::displayInfo()
{
    Footballer::displayInfo();
    cout << "Tackle Success: " << this->tackleSuccess << endl;
    cout << "Interceptions: " << this->interceptions << endl;
    cout << "Defensive Rating: " << this->defensiveRating() << endl;
}