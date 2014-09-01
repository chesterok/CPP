#include <iostream>
#include "Mohican.h"

int main() {
    Mohican* m1 = new Mohican("m1");
    Mohican* m2 = new Mohican("m2");
    Mohican* m3 = new Mohican("m3");
    Mohican* m4 = new Mohican("m4");
    Mohican* m5 = new Mohican("m5");

    delete m3;
    delete m4;
    delete m5;

    std::cout << Mohican::getLastMohican().getName() << std::endl;

    delete m2;
    delete m1;

    return 0;
}
