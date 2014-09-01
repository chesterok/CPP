#include "Iterator.h"

GPIterator::GPIterator(int first, int multiplier, int quantity) : 
          first(first),
          multiplier(multiplier),
          quantity(quantity),
          value(first),
          currentIndex(1) 
{
    if ( multiplier == 0 ) {
        throw InvalidMultiplier();
    }
    if ( first == 0 ) {
        throw InvalidFirst();
    }
}

bool GPIterator::over() const {
    return currentIndex >= quantity;
}

bool GPIterator::less() const {
    return currentIndex <= 1;
}

void GPIterator::GPIterator::next() {
    if ( over() ) {
        return;
    }
    currentIndex += 1;
    value *= multiplier;        
}

void GPIterator::previous() {
    if ( less() ) {
        return;
    }
    currentIndex -= 1;
    value /= multiplier;
}

void GPIterator::reset() {
    value = first;
    currentIndex = 1;
}

void GPIterator::operator++() {
    next();
}

void GPIterator::operator--() {
    previous();
}

void GPIterator::operator--(int) {
    operator--();
}

void GPIterator::operator++(int) {
    operator++(); 
}

int GPIterator::getValue() const {
    return value;
}

int GPIterator::operator*() const {
    return getValue();
}

int GPIterator::getValueAtIndex(int index) {
    int newValue = first * pow(multiplier, index - 1);

    if ( index < 1 || index > quantity ) {
         throw InvalidIndex();
    }

    return newValue;
}

void GPIterator::jumpToIndex(int index) {
    value = getValueAtIndex(index);
    currentIndex = index;
}
