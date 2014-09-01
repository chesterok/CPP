#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "SpellCaster.h"
#include "Heal.h"

class Healer : public SpellCaster {
    public:
        Healer(const std::string& name="Healer", int hp=150, int dmg=10, int mana=100);
        ~Healer();    
};

#endif // HEALER_H
