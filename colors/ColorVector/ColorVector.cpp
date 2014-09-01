#include "ColorVector.h"

ColorVector::ColorVector(std::string color, double x, double y) : color(color), Vector(x, y) {}

void ColorVector::operator+=(const ColorVector& other) {
    color.append("+" + other.color);
    Vector::operator += (other);
}

void ColorVector::operator+=(const Vector& other) {
    Vector::operator+=(other);
}

void ColorVector::operator-=(const ColorVector& other) {
    color.append("-" + other.color);
    Vector::operator -= (other);
}

void ColorVector::operator-=(const Vector& other) {
    Vector::operator-=(other);
}

ColorVector ColorVector::operator+(const ColorVector& other) {
    ColorVector sum = *this;

    sum += other;

    return sum;
}

ColorVector ColorVector::operator+(const Vector& other) {
    ColorVector sum = *this;

    sum += other;

    return sum;
}


ColorVector ColorVector::operator-(const ColorVector& other) {
    ColorVector diff = *this;

    diff -= other;

    return diff;
}

ColorVector ColorVector::operator-(const Vector& other) {
    ColorVector diff = *this;

    diff -= other;

    return diff;
}

bool ColorVector::operator==(const ColorVector& other) const {
    return x == other.x && y == other.y && color  == other.color;
}

bool ColorVector::operator==(const Vector& other) const {
    return Vector::operator==(other);
}

bool ColorVector::operator!=(const Vector& other) const {
    return !operator==(other);
}

bool ColorVector::operator!=(const ColorVector& other) const {
    return !operator==(other);
}

const std::string& ColorVector::getColor() const {
    return color;
}

std::ostream& operator<<(std::ostream& out, const ColorVector& vector) {
    out << (Vector)vector << ' ' << vector.getColor();
    
    return out;
}
