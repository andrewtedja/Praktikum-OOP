#include "User.h"
#include <iostream>
using namespace std;

User::User(char *name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
};

User::User(const User &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
}

User::~User() {};