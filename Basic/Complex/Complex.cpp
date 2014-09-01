#include "Complex.h"

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

Complex::~Complex() {}

double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imaginary;
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imaginary == other.imaginary;
}

bool Complex::operator!=(const Complex& other) const {
    return !operator==(other);
}

void Complex::operator+=(const Complex& other) {
    real += other.real;
    imaginary += other.imaginary;
}

void Complex::operator-=(const Complex& other) {
    real -= other.real;
    imaginary -= other.imaginary;
}

Complex Complex::operator+(const Complex& other) const {
    Complex sum = *this;

    sum += other;

    return sum;
}

Complex Complex::operator-(const Complex& other) const {
    Complex diff = *this;

    diff -= other;

    return diff;
}

Complex Complex::operator*(const Complex& other) const {
    Complex multiply;

    multiply.real = real * other.real - imaginary * other.imaginary;
    multiply.imaginary = imaginary * other.real + real * other.imaginary;

    return multiply;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    out << '(' << complex.getReal();
    if ( complex.getImaginary() >= 0 ) {
        out << '+';
    }
    out << complex.getImaginary() << "i)";

    return out;
}
