#include "Passport.h"

bool Passport::isLetter(char& symbol) {
    bool letter = false;

    if ( symbol >= 'A' && symbol <= 'Z' || symbol >= 'a' && symbol <= 'z' ) {
        if ( symbol > 'Z' ) {
            int diff = 'a' - 'A';

            symbol -= diff;
        }
        letter = true;
    }

    return letter;
}

void Passport::validate() {
    lastSerial += 1;

    if ( lastSerial == 1000000 ) {
        lastSerial = 0;
        lastSecond += 1;

        if ( lastSecond == '[' ) {
            lastSecond = 'A';
            lastFirst += 1;

            if ( lastFirst == '[' ) {
                throw new NumbersOut();
            }
            
        }
    }

    serial = lastSerial;
    first = lastFirst;
    second = lastSecond;
}

Passport::Passport(const char* name, const char* secondName, int day, int month, int year) 
        : name(name), secondName(secondName), date(day, month, year)
{
    validate();
}

void Passport::setSerial(char a, char b, int serial) {
    if ( !isLetter(a) || !isLetter(b) || serial > 999999 || serial < 0 ) {
        throw new InvalidSerial();
    }

    first = a;
    second = b;
    this->serial = serial;
}

int Passport::getSerial() const {
    return serial;
}

const char* Passport::getName() const {
    return name;
}

const char* Passport::getSecondName() const {
    return secondName;
}

Date Passport::getDate() const {
    return date;
}

char Passport::getFirst() const {
    return first;
}

char Passport::getSecond() const {
    return second;
}

int Passport::lastSerial = 0;
char Passport::lastFirst = 'A';
char Passport::lastSecond = 'A';

std::ostream& operator<<(std::ostream& out, Passport& passport) {
    out.fill('0');

    out << "serial number: " << passport.getFirst() << passport.getSecond() << std::setw(6) << passport.getSerial() << "\n";
    out << "born: ";
    out << passport.getDate() << std::endl;
    out << "name: " << passport.getName() << ' ' << passport.getSecondName() << std::endl;

    return out;
}
