#ifndef FIRE_BALL_H
#define FIRE_BALL_H

#include <iostream>
#include "Spell.h"

class FireBall : public Spell {
    public:
        FireBall(int spellPoints = 30) : Spell(spellPoints) {}
        void action(Unit* target);
};

#endif // FIRE_BALL_H