#include "Car.h"

Car::Car(double capacity, double consumption, const Point& location, const std::string& model) :
    fuelCapacity(capacity),
    fuelConsumption(consumption),
    location(location),
    model(model),
    fuelAmount(capacity) 
{

}

Car::~Car() {

}

double Car::getFuelAmount() const {
    return fuelAmount;
}

double Car::getFuelCapacity() const {
    return fuelCapacity;
}

double Car::getFuelConsumption() const {
    return fuelConsumption;
}

const Point& Car::getLocation() const {
    return location;
}

const std::string& Car::getModel() const {
    return model;
}

void Car::drive(const Point& destination) {
    double fuelNeed = location.distance(destination) * fuelConsumption;

    if ( fuelNeed > fuelAmount ) { throw OutOfFuel(); }

    location = destination;
    fuelAmount -= fuelNeed;
}

void Car::drive(double x, double y) {
    Point destination(x, y);

    drive(destination);
}

void Car::refill(double fuel) {
    if ( fuel > 0 ) {
        double newFuel = fuel + fuelAmount;

        if ( newFuel > fuelCapacity ) { throw ToMuchFuel(); }

        fuelAmount = newFuel;
    }
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << "Car \"" << car.getModel() << "\":" << std::endl;
    out << "-- Fuel Amount: " << car.getFuelAmount() << std::endl;
    out << "-- Fuel Capacity: " << car.getFuelCapacity() << std::endl;
    out << "-- Fuel Consumption: " << car.getFuelConsumption() << std::endl;
    out << "-- Location: " << car.getLocation() << std::endl;

   return out;
}
