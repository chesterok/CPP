#include "SpellCaster.h"


SpellCaster::SpellCaster(const std::string& name, int hp, int dmg, int mana) 
            : Unit(name, hp, dmg), mana(mana), manaLimit(mana) {}

SpellCaster::~SpellCaster() {}

int SpellCaster::getMana() const {
    return mana;
}

int SpellCaster::getManaLimit() const {
    return manaLimit;
}

void SpellCaster::spendMana(int cost) {
    ensureIsAlive();

    if ( cost > mana ) {
        throw new OutOfManaException();
    }
    mana -= cost;
}

void SpellCaster::addMana(int extra) {
    ensureIsAlive();

    int total = mana + extra;

    if ( total > mana ) {
        mana = manaLimit;
        return;
    }
    mana = total;
}

void SpellCaster::cast(Unit* target) {
    spendMana(spell->getSpellPoints());
    spell->action(target);
}

void SpellCaster::changeSpell(Spell* newSpell) {
    spell = newSpell;
}

std::ostream& operator<<(std::ostream& out, const SpellCaster* mage) {
    out << (Unit*)mage << "-- Mana: " << mage->getMana() << "/" << mage->getManaLimit() << std::endl;
    return out;
}
