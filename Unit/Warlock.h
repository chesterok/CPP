#ifndef WARLOCK_H
#define WARLOCK_H

#include <iostream>
#include "SpellCaster.h"
#include "Demon.h"
#include "FireBall.h"

class Demon;

class Warlock : public SpellCaster {
    protected:
        Demon* demon;

        void ensureIsAlive();

    public:
        Warlock(const std::string& name="Warlock", int hp=150, int dmg=10, int mana=100);
        ~Warlock();

        void summon();
        Demon* getDemon();
        void freeSlave();
};


#endif // WARLOCK_H
