#ifndef PASSPORT_H
#define PASSPORT_H

#include <iostream>
#include <iomanip>
#include "Date.h"

class NumbersOut {};
class InvalidSerial {};

class Passport {
private:
    const char* name;
    const char* secondName;
    Date date;
    int serial;
    char first, second;
    static char lastFirst, lastSecond;
    static int lastSerial;
    
    void validate();
    bool isLetter(char& symbol);

public:
    Passport(const char* name="Ivan", const char* secondName="Petrov", int day = 1, int month = 1, int year = 1970);
    void setSerial(char a, char b, int serial = 1);
    int getSerial() const;
    const char* getName() const;
    const char* getSecondName() const;
    Date getDate() const;
    char getFirst() const;
    char getSecond() const;
};

std::ostream& operator<<(std::ostream& out, Passport& passport);

#endif // PASSPORT_H
