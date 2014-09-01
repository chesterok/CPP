#include "FireBall.h"

void FireBall::action(Unit* target) {
    target->takeDamage(spellPoints);
}