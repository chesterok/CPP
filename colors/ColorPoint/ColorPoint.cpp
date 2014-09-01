#include "ColorPoint.h"

ColorPoint::ColorPoint(std::string color, double x, double y) : color(color), Point(x, y) {}

const std::string& ColorPoint::getColor() const {
    return color;
}

bool ColorPoint::operator==(const ColorPoint& other) const {
    return x == other.x && y == other.y && color  == other.color;
}

bool ColorPoint::operator==(const Point& other) const {
    return Point::operator==(other);
}

bool ColorPoint::operator!=(const Point& other) const {
    return !operator==(other);
}

bool ColorPoint::operator!=(const ColorPoint& other) const {
    return !operator==(other);
}

std::ostream& operator<<(std::ostream& out,const ColorPoint& point) {
    out << (Point)point << ' ' << point.getColor();

    return out;
}
