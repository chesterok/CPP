#include "Iterator.h"

NaturalIterator::NaturalIterator(int limit) : limit(limit), current(1), maxSize(1) {
    pointer = (int*)malloc(limit*sizeof(int));
    if ( pointer == NULL ) {
        throw OutOfMemory();
    }

    pointer[current] = 2;
}

const int NaturalIterator::operator[](int index) const {
    return pointer[index];
}

void NaturalIterator::next() {
    if ( over() ) {
        return;
    }

    if ( maxSize == current ) {
        for ( int i = pointer[current] + 1; i <= i; i++ ) {
            bool prime = true;

            for ( int j = 2; j <= sqrt(i); j++ )  {
                if ( i % j == 0 ) { 
                    prime = false;
                    break;
                }
            }
            if ( prime ) {
                current += 1;
                maxSize = current;
                pointer[current] = i;
                break;
            }
        }
    } else {
        current += 1;
    }
}

void NaturalIterator::reset() {
    current = 1;
}

void NaturalIterator::jumpToIndex(int index) {
    if ( index < 1 ) {
        throw InvalidIndex();
    }

    if ( index > maxSize ) {
        current = maxSize;

        for ( int i = maxSize; i < index; i++ ) {
            next();
        }
    } else {
        current = index;
    }
}

int NaturalIterator::getValueAtIndex(int index) {
    int tempCurrent = current;

    jumpToIndex(index);

    index = current;
    current = tempCurrent;

    return pointer[index];
}

void NaturalIterator::previous() {
    if ( less() ) {
        return;
    }

    current -= 1;
}

void NaturalIterator::operator--() {
    previous();
}

void NaturalIterator::operator--(int) {
    operator--();
}

void NaturalIterator::operator++() {
    next(); 
}

void NaturalIterator::operator++(int) { 
    operator++();
}

bool NaturalIterator::less() const {
    return current < 0;
}

bool NaturalIterator::over() const {
    return current >= limit;
}

int NaturalIterator::getValue() const {
    return pointer[current];
}

int NaturalIterator::operator*() {
    return getValue();
}
