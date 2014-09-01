#include <iostream>
#include "Vector.h"
#include "ColorVector.h"

using namespace std;

int main() {
    Vector a(1, 2);
    Vector b(3, 2);
    Vector c;
    ColorVector x("Red", 7, 2);
    ColorVector s("Green", 7, 2);
    ColorVector w;

    w = x + s;
    w += x;

    cout << w + w - x - s << endl;

    std::cout << "Absolute value: " << a.vectorLen(b) << std::endl;   
    std::cout << "a:" << a << std::endl;
    std::cout << "b:" << b << std::endl;
    std::cout << "c:" << c << std::endl;
 
    if ( x != s ) {
        std::cout << x << " is not equal to " << s << std::endl;
    } else {
        std::cout << x << " is equal to " << s << std::endl;
    }

    x += s;
    std::cout << "increment x: " << x << std::endl;
    x -= s;
    std::cout << "decrement x: " << x << std::endl;
    std::cout << "sum(x, s): " << x+s << std::endl;
    std::cout << "diff(x, s): " << x-s << std::endl;

    return 0;
}
