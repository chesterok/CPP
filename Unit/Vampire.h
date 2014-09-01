#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include "Unit.h"

class Vampire : public Unit {
    private:
        void vampirism(Unit* enemy, int damage);
        
    public:
        Vampire(const std::string& name="Vampire", int hp=200, int dmg=20);
        void attack(Unit* enemy);
        void counterAttack(Unit* enemy);
        ~Vampire();
};

#endif //VAMPIRE_H
