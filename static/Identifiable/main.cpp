#include <iostream>
#include "Identifiable.h"

int main() {
    Identifiable* a = new Identifiable();
    Identifiable* b = new Identifiable();
    Identifiable* c = new Identifiable();

    std::cout << "id a : " << a->getId() << std::endl;

    return 0;
}
