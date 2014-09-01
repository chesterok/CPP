#ifndef HEAL_H
#define HEAL_H

#include <iostream>
#include "Spell.h"

class Heal : public Spell {
    public:
        Heal(int spellPoints = 30) : Spell(spellPoints) {}
        void action(Unit* target);
};

#endif // HEAL_H
