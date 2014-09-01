#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include <iostream>
#include "Unit.h"
#include "Spell.h"

class OutOfManaException {};

class SpellCaster : public Unit {
    protected:
        int mana;
        int manaLimit;
        Spell* spell;

    public:
        SpellCaster(const std::string& name, int hp, int dmg, int mana);
        virtual ~SpellCaster();

        int getMana() const;
        int getManaLimit() const;
        void spendMana(int extra);
        void addMana(int extra);
        virtual void cast(Unit* target);
        void changeSpell(Spell* newSpell);       
};

std::ostream& operator<<(std::ostream& out, const SpellCaster* mage);

#endif //SPELL_CASTER_H
