#include "Rogue.h"

Rogue::Rogue(const std::string& name, int hp, int dmg) : Unit(name, hp, dmg) {}

Rogue::~Rogue() {}

void Rogue::attack(Unit* enemy) {
    enemy->takeDamage(damage);
}
