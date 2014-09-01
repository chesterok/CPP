#include "Date.h"

void Date::validate(int day, int month, int year) {
    if ( day > 31 || day < 1 ) {
        throw InvalidDate("Incorrect day");    
    }        
    if ( month > 12 || month < 1 ) {
        throw InvalidDate("Incorrect month");    
    }
    if ( year < 0 ) {
        throw InvalidDate("Incorrect year");    
    }
    if ( month == 2 ) {
        if ( year % 4 == 0 ) {
            if ( day > 29 ) {
                throw InvalidDate("In leap year february has 29 days");
            }
        } else {
            if ( day > 28 ) {
                throw InvalidDate("In normal year february has 28 days");
            }
        }       
    }
    if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
        if ( day > 30 ) {
            throw InvalidDate("In this month can not be 31 day");
        }
    }
}

Date::Date(int day, int month, int year) :
     day(day),
     month(month),
     year(year)
{
    validate(day, month, year);
}

Date::~Date() {}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

std::ostream& operator<<(std::ostream& out,const Date& date) {
    if ( date.getDay() < 10 ) {
        out << '0';
    }
    out << date.getDay() << '.' ;
    if ( date.getMonth() < 10 ) {
        out << '0';
    }
    out << date.getMonth() << '.' << date.getYear();

    return out;
}
