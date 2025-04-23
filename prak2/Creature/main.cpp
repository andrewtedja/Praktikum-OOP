#include "Creature.hpp"
#include "Dragon.hpp"

int main()
{
    // Lengkapi disini
    Dragon d = Dragon("Draco");
    Creature *c = &d;
    Creature c2(*c);
    d.speak();
    d.wound();
    d.wound();
    d.print();
    d.speak();

    c->wound();
    c->print();
    d.print();

    c2.speak();
    c2.wound();
    c2.wound();

    c2.print();

    d.print();
    return 0;
}
