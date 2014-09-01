#include <iostream>
#include <cmath>
#include "Vector.h"

Vector::Vector(double x, double y) : x(x), y(y) {}

Vector::~Vector() {}

double Vector::Vector::getX() const {
    return x;
}

double Vector::getY() const {
    return y;
}

void Vector::setX(double value) {
    this->x = value;
}

void Vector::setY(double value) {
    this->y = value;
}

double Vector::distance() const {
    return hypot(x, y);
}

bool Vector::operator==(const Vector& other) const {
    return x == other.x && y == other.y;
}

bool Vector::operator!=(const Vector& other) const {
    return !operator==(other);
}

void Vector::operator+=(const Vector& other) {
    x += other.x;
    y += other.y;
}

void Vector::operator-=(const Vector& other) {
    x -= other.x;
    y -= other.y;
}

Vector Vector::operator+(const Vector& other) const {
    Vector sum = *this;

    sum += other;

    return sum;
}

Vector Vector::operator-(const Vector& other) const {
    Vector diff = *this;

    diff -= other;

    return diff;
}
