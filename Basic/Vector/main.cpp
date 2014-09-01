#include <iostream>
#include "Vector.h"

int main() {
    Vector x(2, 7);
    Vector y(3, 8);
    Vector z;

    std::cout << "x: " << '(' << x.getX() << ", " << x.getY() << ')' << std::endl;
    std::cout << "y: " << '(' << y.getX() << ", " << y.getY() << ')' << std::endl;
    std::cout << "z: " << '(' << z.getX() << ", " << z.getY() << ')' << std::endl;

    if ( x == y ) {
       std::cout << '(' << x.getX() << ", " << x.getY() << ')' << " is equal to ";
       std::cout << '(' << y.getX() << ", " << y.getY() << ')' << std::endl;
    } else {
       std::cout << '(' << x.getX() << ", " << x.getY() << ')' << " is not equal to ";
       std::cout << '(' << y.getX() << ", " << y.getY() << ')' << std::endl;
    }

    std::cout << "Distance x: " << x.distance() << std::endl;

    std::cout << "increment x: ";
    x += y;
    std::cout << '(' << x.getX() << ", " << x.getY() << ')' << std::endl;

    std::cout << "decrement x: ";
    x -= y;
    std::cout << '(' << x.getX() << ", " << x.getY() << ')' << std::endl;

    std::cout << "sum(x, y): ";
    z = x + y;
    std::cout << '(' << z.getX() << ", " << z.getY() << ')' << std::endl;

    std::cout << "diff(x, y): ";
    z = x - y;
    std::cout << '(' << z.getX() << ", " << z.getY() << ')' << std::endl;

    return 0;
}
