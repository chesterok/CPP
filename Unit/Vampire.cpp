#include "Vampire.h"

Vampire::Vampire(const std::string& name, int hp, int dmg) : Unit(name, hp, dmg) {}

void Vampire::vampirism(Unit* enemy, int damage) {
    if ( enemy->getHitPoints() > damage ) {
        addHitPoints(damage / 3);
    } else {
        addHitPoints(enemy->getHitPoints() / 3);
    }
}

void Vampire::attack(Unit* enemy) {
    vampirism(enemy, this->damage);
    Unit::attack(enemy);
}

void Vampire::counterAttack(Unit* enemy) {
    vampirism(enemy, this->damage / 2);
    Unit::counterAttack(enemy);
}

Vampire::~Vampire() {}

