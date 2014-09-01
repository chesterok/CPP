#include <iostream>
#include "Countable.h"

int main() {
    Countable* a = new Countable();
    Countable* b = new Countable();
    Countable* c = new Countable();

    delete c;

    std::cout << "Quantity: " << Countable::getCounter() << std::endl;

    return 0;
}
