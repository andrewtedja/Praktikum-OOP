#include "Pokemon.hpp"
#include "FirePokemon.hpp"
#include "GrassPokemon.hpp"
#include "WaterPokemon.hpp"

int main()
{
    FirePokemon *f1 = new FirePokemon("Charmander");
    // FirePokemon f2(f1);
    FirePokemon *f2 = new FirePokemon(*f1);
    WaterPokemon w1("Squirtle", 100, 20, 10);
    w1.heal(10);
    WaterPokemon *w2 = new WaterPokemon("Magikarp");
    *w2 = w1;
    w1.attack(*f1);
    w1.attack(*f1);
    delete f1;
}
