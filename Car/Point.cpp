#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {}

Point::~Point() {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::distance(const Point& other) const {
    return hypot(x-other.x, y-other.y);
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !operator==(other);
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.getX() << ", " << point.getY() << ")";

    return out;
}
