#include "Iterator.h"

FibonacciIterator::FibonacciIterator(int lessLimit, int overLimit) :
                 lessLimit(lessLimit),
                 overLimit(overLimit)
{
    if ( lessLimit > overLimit ) {
        throw InvalidIndex();
    }

    pointer = (int*)malloc(std::max(abs(lessLimit), abs(overLimit))*sizeof(int));
    if ( pointer == NULL ) {
        throw OutOfMemory();
    }
    pointer[0] = 0;
    pointer[1] = 1;

    for ( int i = 1; i <= abs(lessLimit); i++ ) {
            pointer[i+1] = pointer[i] + pointer[i-1];
    }

    current = lessLimit;
    maxSize = abs(lessLimit);
}

void FibonacciIterator::next() {
    if ( over() ) {
        return;
    }
    current += 1;
    if ( maxSize <= current ) {
        maxSize += 1;
        if ( current > 1 ) {
            pointer[current] = pointer[current-1] + pointer[current-2];
        }
    }
 }

void FibonacciIterator::previous() {
    if ( less() ) {
        return;
    }
    current -= 1;
}

void FibonacciIterator::operator++() {
    next();
}

void FibonacciIterator::operator--() {
    previous();
}

void FibonacciIterator::operator++(int) {
    operator++();
}

void FibonacciIterator::operator--(int) {
    operator--();
}

bool FibonacciIterator::over() { 
    return current >= overLimit;
}

bool FibonacciIterator::less() { 
    return current <= lessLimit;
}

void FibonacciIterator::reset() {
   current = lessLimit; 
}

int FibonacciIterator::getValue() {
    if ( current < 0 ) {
        int newCurrent = current;

        newCurrent *= -1;
        if ( newCurrent % 2 == 0 ) {

            return pointer[newCurrent] * -1;
        }

        return pointer[newCurrent];
    }

    return pointer[current];
}

int FibonacciIterator::getValueAtIndex(int index) {
    int tempCurrent = current;

    jumpToIndex(index);
    index = getValue();
    current = tempCurrent;

    return index;
}

void FibonacciIterator::jumpToIndex(int index) {
    if ( index < lessLimit || index > overLimit ) {
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

int FibonacciIterator::operator*() {
    return getValue();
}
