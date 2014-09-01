#include "Iterator.h"

APIterator::APIterator(int first, int last, int step) : 
          first(first),
          last(last),
          step(step),
          value(first) 
{
    if ( first > last || step <= 0 ) {
        throw InvalidParam();
    }

}

void APIterator::next() {
    if ( over() ) {
        return;
    }
    value += step;
}

void APIterator::previous() {
    if ( less() ) {
        return;
    }
    value -= step;
}

bool APIterator::less() {
    return value - step < first;
}

void APIterator::operator--() {
    previous();
}

void APIterator::operator--(int) {
    operator--();
}

void APIterator::operator++() {
    next();
}

void APIterator::operator++(int) {
    operator++();
}

int APIterator::operator*() {
    return getValue();
}

bool APIterator::over() {
    return value + step > last;
}

int APIterator::getValue() const {
    return value;
}

void APIterator::reset() {
    value = first;
}

int APIterator::getValueAtIndex(int index) {
    int newValue = first + step * index - step;

    if ( index < 1 || newValue > last ) {
         throw InvalidIndex();
    }

    return newValue;
}

void APIterator::jumpToIndex(int index) {
    value = getValueAtIndex(index);
}
