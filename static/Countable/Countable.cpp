#include "Countable.h"

int Countable::counter = 0;
int Countable::getCounter() {
    return counter;
}

Countable::Countable() {
    counter += 1;
}

Countable::~Countable() {
    counter -= 1;
}
