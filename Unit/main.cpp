#include <iostream>
#include "Unit.h"
#include "Soldier.h"
#include "Rogue.h"
#include "Vampire.h"
#include "Healer.h"
#include "Wizzard.h"
#include "Warlock.h"
#include "Demon.h"

using namespace std;

int main() {
    Soldier *soldier = new Soldier("Soldier", 150, 30);
    Rogue *rogue = new Rogue("Rogue", 100, 30);
    Vampire *vampire = new Vampire("Vampire", 200, 20);
    Wizzard *wizzard = new Wizzard("Wizzard", 120, 10, 150);
    Healer *healer = new Healer("Healer", 120, 10, 150);
    Warlock *warlock = new Warlock("Warlock", 100, 10, 150);

    cout << soldier << endl;
    cout << rogue << endl;
    cout << vampire << endl;
    cout << wizzard << endl;
    cout << healer << endl;

    cout << endl << "epic battle!" << endl;

    rogue->attack(vampire);
    rogue->attack(vampire);
    vampire->attack(soldier);
    wizzard->cast(rogue);
    healer->cast(rogue);
    warlock->summon();
    warlock->getDemon()->attack(soldier);
    wizzard->changeSpell(new Heal());
    wizzard->cast(rogue);

    cout << warlock << endl;
    cout << warlock->getDemon() << endl;
    cout << soldier << endl;
    cout << rogue << endl;
    cout << vampire << endl;
    cout << wizzard << endl;
    cout << healer << endl;

    delete soldier;
    delete rogue;
    delete vampire;
    delete wizzard;
    delete healer;

    return 0;
}
