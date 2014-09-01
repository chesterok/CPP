#include <iostream>
#include "Car.h"

int main() {
    Car car;

    std::cout << car << std::endl;

    car.drive(Point(5, 11));

    std::cout << car << std::endl;
    
    return 0;
}
