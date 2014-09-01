#include "Unit.h"

void Unit::ensureIsAlive() {
    if ( hitPoints == 0 ) {
        throw UnitIsDead();
    }
}

Unit::Unit(const std::string& name, int hp, int dmg) :
     damage(dmg),
     hitPoints(hp),
     hitPointsLimit(hp),
     name(name)
{

}

Unit::~Unit() {}

int Unit::getDamage() const {
    return damage;
}

int Unit::getHitPoints() const {
    return hitPoints;
}

int Unit::getHitPointsLimit() const {
    return hitPointsLimit;
}

const std::string& Unit::getName() const {
    return name;
}

void Unit::addHitPoints(int hp) {
    ensureIsAlive();

    int newHp = hitPoints + hp;

    if ( newHp > hitPointsLimit ) {
        hitPoints = hitPointsLimit;
    } else {
        hitPoints = newHp;
    }
}

void Unit::takeDamage(int dmg) {
    ensureIsAlive();

    if ( dmg > hitPoints ) {
        hitPoints = 0;
    } else {
        hitPoints -= dmg;
    }
}

void Unit::attack(Unit* enemy) {
    enemy->takeDamage(damage);
    enemy->counterAttack(this);
}

void Unit::counterAttack(Unit* enemy) {
    enemy->takeDamage(damage/2);
}

std::ostream& operator<<(std::ostream& out, const Unit* unit) {
    out << "Unit \"" << unit->getName() << "\":" << std::endl;
    out << "-- Damage: " << unit->getDamage() << std::endl;
    out << "-- Hit Points: " << unit->getHitPoints() << "/" << unit->getHitPointsLimit() << std::endl;

   return out;
}
