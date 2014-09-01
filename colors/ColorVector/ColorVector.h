#ifndef COLORVECTOR_H
#define COLORVECTOR_H

#include <iostream>
#include "Vector.h"

class ColorVector : public Vector {
private:
    std::string color;

public:
    ColorVector(std::string color="Red", double x=0, double y=0);
    void operator+=(const ColorVector& other);
    void operator+=(const Vector& other);
    void operator-=(const ColorVector& other);
    void operator-=(const Vector& other);
    ColorVector operator+(const ColorVector& other);
    ColorVector operator+(const Vector& other);
    ColorVector operator-(const ColorVector& other);
    ColorVector operator-(const Vector& other);
    bool operator==(const ColorVector& other) const;
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
    bool operator!=(const ColorVector& other) const;
    const std::string& getColor() const;
};

std::ostream& operator<<(std::ostream& out, const ColorVector& vector);

#endif // COLORVECTOR_H
