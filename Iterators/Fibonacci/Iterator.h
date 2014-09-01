#ifndef FIBONACCI_ITERATOR_H
#define FIBONACCI_ITERATOR_H

#include <iostream>
#include <cstdlib>
#include <algorithm>

class OutOfMemory {};
class InvalidIndex {};

class FibonacciIterator {
    private:
        int* pointer;
        int lessLimit, overLimit;
        int current;
        int maxSize;

    public:
        FibonacciIterator(int lessLimit=-10, int overLimit=10);

        void next();
        void previous();
        bool over();
        bool less();

        void operator++();
        void operator--();
        void operator++(int);
        void operator--(int);
        int operator*();

        void reset();
        void jumpToIndex(int index);
        int getValue();
        int getValueAtIndex(int index);
};

#endif //FIBONACCI_ITERATOR_H
