#include "Spell.h"

Spell::Spell(int spellPoints) : spellPoints(spellPoints) {}

Spell::~Spell() {}

int Spell::getSpellPoints() const {
    return spellPoints;
}
