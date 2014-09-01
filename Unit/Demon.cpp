#include "Demon.h"

void Demon::ensureIsAlive() {
    if ( hitPoints == 0 ) {
        master->freeSlave();
        throw new UnitIsDead();
    }
}

Demon::Demon(Warlock* master, const std::string& name, int hp, int dmg) 
     : Soldier(name, hp, dmg), master(master) {}

Demon::~Demon() {}
