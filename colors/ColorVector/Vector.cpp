#include "Vector.h"

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::getX() const {
    return x;
}

double Vector::getY() const {
    return y;
}

double Vector::vectorLen(const Vector& x) const {
    return hypot(x.x, x.y);
}

void Vector::operator+=(const Vector& other) {
    x += other.x;
    y += other.y;
}

void Vector::operator-=(const Vector& other) {
    x -= other.x;
    y -= other.y;
}

bool Vector::operator==(const Vector& other) const {
    return x == other.x && y == other.y;
}

bool Vector::operator!=(const Vector& other) const {
    return !operator==(other);
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

std::ostream& operator<<(std::ostream& out, const Vector& vector) {
    out << "(" << vector.getX() << ", " << vector.getY() << ")" ;
    
    return out;
}
