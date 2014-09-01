#ifndef DEMON_H
#define DEMON_H

#include <iostream>
#include "Soldier.h"
#include "Warlock.h"

class Warlock;

class Demon : public Soldier {
    protected:
        Warlock* master;

        void ensureIsAlive();

    public:
        Demon(Warlock* master, const std::string& name="Demon", int hp=150, int dmg=20);
        ~Demon();
};

#endif //DEMON_H
