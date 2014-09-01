#include "Iterator.h"

FactorialIterator::FactorialIterator(int limit) : limit(limit), current(1), value(1) {
    if ( limit < 0 ) {
        throw InvalidParam();
    }
}

void FactorialIterator::next() {
    if ( over() ) {
        return;
    }
    value *= current;
    current += 1;
}

void FactorialIterator::previous() {
    if ( less() ) {
        return;
    }
    current -= 1;
    value /= current;
}

void FactorialIterator::reset() {
    value = 1;
    current = 1;
}

bool FactorialIterator::over() const {
    return current >= limit;
}

bool FactorialIterator::less() const {
    return current <= 1;
}

void FactorialIterator::operator++() {
    next();
}

void FactorialIterator::operator--() {
    previous();
}

void FactorialIterator::operator--(int) {
    operator--();
}

void FactorialIterator::operator++(int) {
    operator++();
}

unsigned long long FactorialIterator::getValue () const {
    return value;
}

unsigned long long FactorialIterator::operator*() const {
    return getValue();
}

int FactorialIterator::getValueAtIndex(int index) {
    int newValue = 1;

    if ( index < 0 || index >= limit ) {
        throw InvalidIndex();
    }

    for ( int i = 1; i <= index; i++ ) {
        newValue *= i;
    }

    return newValue;
}

void FactorialIterator::jumpToIndex(int index) {
    value = getValueAtIndex(index);
    current = index + 1;
}
