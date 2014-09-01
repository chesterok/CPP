#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vector {
protected:
    double x;
    double y;

public:
    Vector(double x=0, double y=0);
    double getX() const;
    double getY() const;
    double vectorLen(const Vector&) const;
    bool operator==(const Vector&) const;
    bool operator!=(const Vector&) const;
    void operator+=(const Vector&);
    void operator-=(const Vector&);
    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
};

std::ostream& operator<<(std::ostream&, const Vector&);

#endif // VECTOR_H
