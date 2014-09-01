#ifndef UNIT_H
#define UNIT_H

#include <iostream>

class UnitIsDead {};

class Unit {
    protected:
        int damage;
        int hitPoints;
        int hitPointsLimit;
        std::string name;
        void ensureIsAlive();

    public:
        Unit(const std::string& name, int hp, int dmg);
        virtual ~Unit();

        int getDamage() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        const std::string& getName() const;

        void addHitPoints(int hp);
        void takeDamage(int dmg);

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit* unit);

#endif //UNIT_H
