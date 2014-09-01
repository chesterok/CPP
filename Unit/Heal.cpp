#include "Heal.h"

void Heal::action(Unit* target) {
    target->addHitPoints(spellPoints);
}
