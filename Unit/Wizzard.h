#ifndef WIZZARD_H
#define WIZZARD_H

#include <iostream>
#include "SpellCaster.h"
#include "FireBall.h"

class Wizzard : public SpellCaster {
    public:
        Wizzard(const std::string& name="Wizzard", int hp=150, int dmg=10, int mana=100);
        ~Wizzard();    
};

#endif // WIZZARD_H
