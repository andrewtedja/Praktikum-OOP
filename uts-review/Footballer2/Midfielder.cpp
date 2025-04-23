#include "Midfielder.hpp"
#include <bits/stdc++.h>

Midfielder::Midfielder() : Footballer()
{
    this->assist = 0;
    this->keyPasses = 0;
    this->playPosition = "midfielder";
}

Midfielder::Midfielder(string name, int birthYear, int assist, int keyPasses) : Footballer()
{
    this->name = name;
    this->birthYear = birthYear;
    this->assist = assist;
    this->keyPasses = keyPasses;
    this->playPosition = "midfielder";
}

int Midfielder::setAssist(int n)
{
    this->assist = n;
    return n;
}

int Midfielder::getAssist() const
{
    return this->assist;
}

int Midfielder::setKeyPasses(int n)
{
    this->keyPasses = n;
    return n;
}

int Midfielder::getKeyPasses() const
{
    return this->keyPasses;
}

int Midfielder::playmakerRating()
{
    return (this->assist * 3) + this->keyPasses;
}

int Midfielder::transferRate()
{
    return (800000 * this->assist) + (30000 * this->keyPasses);
}

void Midfielder::displayInfo()
{
    Footballer::displayInfo();
    cout << "Assists: " << this->assist << endl;
    cout << "Key Passes: " << this->keyPasses << endl;
    cout << "Playmaker Rating: " << this->playmakerRating() << endl;
}
