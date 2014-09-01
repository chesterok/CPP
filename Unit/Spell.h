#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "Unit.h"

class Spell {
    protected:
        int spellPoints;

    public:
        Spell(int spellPoints = 30);
        ~Spell();
        int getSpellPoints() const;
        virtual void action(Unit* target) = 0;
};

#endif // SPELL_H
