#include "Warlock.h"

void Warlock::ensureIsAlive() {
    if ( hitPoints == 0 ) {
        demon = NULL;
        throw new UnitIsDead();
    }
}

Warlock::Warlock(const std::string& name, int hp, int dmg, int mana)
        : SpellCaster(name, hp, dmg, mana) 
{
    demon = NULL;
    spell = new FireBall();
}

Warlock::~Warlock() {
    delete spell;
}

void Warlock::summon() {
    ensureIsAlive();

    if ( demon == NULL ) {
        spendMana(50);
        demon = new Demon(this);
    }
}

Demon* Warlock::getDemon() {
    return demon;
}

void Warlock::freeSlave() {
    demon = NULL;
}
