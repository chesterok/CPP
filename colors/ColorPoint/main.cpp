#include <iostream>
#include "ColorPoint.h"
#include "Point.h"

using namespace std;

int main() {
    Point a(1, 2);
    Point b(4, 9);
    Point c;
    ColorPoint z("Red", 1, 2);
    ColorPoint x("Green", 1, 2);

    if ( x == z ) {
        cout << x << " is equal to " << z << endl;
    } else {
        cout << x << " is not equal to " << z << endl;
    }

    cout << "Distance: " << z.distance(b) << endl;    
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;
 
    if ( a != b ) {
        cout << a << " is not equal to " << b << endl;
    } else {
        cout << a << " is equal to " << b << endl;
    }

    return 0;
}
