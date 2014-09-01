#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "Unit.h"

class Rogue : public Unit {
    public:
        Rogue(const std::string& name="Rogue", int hp=100, int dmg=30);
        void attack(Unit* enemy);
        ~Rogue();
};

#endif //ROGUE_H
