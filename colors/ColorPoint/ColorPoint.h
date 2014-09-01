#ifndef COLORPOINT_H
#define COLORPOINT_H

#include <iostream>
#include "Point.h"

class ColorPoint : public Point {
private:
    std::string color;

public:
    ColorPoint(std::string color ="Red", double x=0, double y=0);
    const std::string& getColor() const;
    bool operator==(const Point& other) const;
    bool operator==(const ColorPoint& other) const;
    bool operator!=(const Point& other) const;
    bool operator!=(const ColorPoint& other) const;
};

std::ostream& operator<<(std::ostream& out, const ColorPoint& point);

#endif // COLORPOINT_H
