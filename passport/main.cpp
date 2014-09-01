#include <iostream>
#include "Passport.h"

using namespace std;

int main() {
    Passport a("Yuriy", "Avilov", 10, 02, 1988);
    Passport b("Mikicey", "Evgeniy", 03, 05, 1988);
    Passport c;

    b.setSerial('a', 'S');

    cout << c << endl;
    cout << b << endl;

    return 0;
}
