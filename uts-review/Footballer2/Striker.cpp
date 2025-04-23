#include "Striker.hpp"
#include <bits/stdc++.h>

Striker::Striker() : Footballer()
{
    this->playPosition = "striker";
    this->goalScore = 0;
    this->shotsOnTarget = 0;
}

Striker::Striker(string name, int birthYear, int goalScore, int shotsOnTarget) : Footballer()
{
    this->name = name;
    this->playPosition = "striker";
    this->birthYear = birthYear;
    this->goalScore = goalScore;
    this->shotsOnTarget = shotsOnTarget;
}

int Striker::setGoalScore(int n)
{
    this->goalScore = n;
    return n;
}

int Striker::getGoalScore() const
{
    return this->goalScore;
}

int Striker::setShotsOnTarget(int n)
{
    this->shotsOnTarget = n;
    return n;
}

int Striker::getShotsOnTarget() const
{
    return this->shotsOnTarget;
}

float Striker::conversionRate()
{
    return (this->shotsOnTarget != 0) ? ((static_cast<float>(this->goalScore) / this->shotsOnTarget) * 100) : 0;
}

int Striker::transferRate()
{
    return static_cast<int>((1000000 * this->goalScore) + (10000 * this->conversionRate()));
}

void Striker::displayInfo()
{
    Footballer::displayInfo();
    cout << "Goals: " << this->goalScore << endl;
    cout << "Conversion Rate: " << fixed << setprecision(2) << this->conversionRate() << "%" << endl;
}
