#include "Wizzard.h"

Wizzard::Wizzard(const std::string& name, int hp, int dmg, int mana) : SpellCaster(name, hp, dmg, mana) 
{
    spell = new FireBall();
}

Wizzard::~Wizzard() {
    delete spell;
}
