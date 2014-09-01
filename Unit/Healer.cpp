#include "Healer.h"

Healer::Healer(const std::string& name, int hp, int dmg, int mana) : SpellCaster(name, hp, dmg, mana) 
{
    spell = new Heal();
}

Healer::~Healer() {
    delete spell;
}
