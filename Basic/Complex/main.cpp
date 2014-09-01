#include <iostream>
#include "Complex.h"

int main() {
    Complex a(3, 2);
    Complex b(9, 2);
    Complex c;

    std::cout << "a:" << a << std::endl;
    std::cout << "b:" << b << std::endl;
    std::cout << "c:" << c << std::endl;
 
    if ( a != b ) {
        std::cout << a << " is not equal to " << b << std::endl;
    } else {
        std::cout << a << " is equal to " << b << std::endl;
    }

    a += b;
    std::cout << "increment a: " << a << std::endl;
    a -= b;
    std::cout << "decrement a: " << a << std::endl;

    std::cout << "sum(a, b): " << a+b << std::endl;

    std::cout << "diff(a, b): " << a-b << std::endl;

    std::cout << "product(a, b): " << a*b << std::endl;

    return 0;
}
