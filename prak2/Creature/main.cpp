#include "Creature.hpp"
#include "Dragon.hpp"
using namespace std;
#include <bits/stdc++.h>
#include <string>

int main()
{
    // Lengkapi disini
    // Dragon d = Dragon("Draco");
    // Creature *c = &d;
    // Creature c2(*c);
    // d.speak();
    // d.wound();
    // d.wound();
    // d.print();
    // d.speak();

    // c->wound();
    // c->print();
    // d.print();

    // c2.speak();
    // c2.wound();
    // c2.wound();

    // c2.print();

    // d.print();
    // return 0;

    // Creature *c = new Creature("Draco");
    // Dragon *c = new Dragon("Draco");

    // c->speak();
    // c->wound();
    // c->wound();
    // c->print();
    // Creature *d = c;
    // d->speak();
    // d->wound();
    // d->print();
    // c->print();
    // Creature c2(*d);
    // c2.speak();
    // c2.wound();
    // c->print();
    // c2.print();
    // delete c;

    Dragon d("Draco");
    d.speak();
    d.wound();
    d.wound();
    d.print();
    Creature *c = &d;
    c->speak();
    c->wound();
    c->print();
    d.print();
    Creature c1 = *c;
    c1.wound();
    c1.print();
    d.print();
}
