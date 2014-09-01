#ifndef FACTORIAL_ITERATOR_H
#define FACTORIAL_ITERATOR_H

#include <iostream>

class InvalidParam {};
class InvalidIndex {};

class FactorialIterator {
    private:
        int limit;
        int current;
        unsigned long long value;

    public:
        FactorialIterator(int limit=10);

        void next();
        void previous();
        void reset();
        bool over() const;
        bool less() const;

        void operator++();
        void operator--();
        void operator--(int);
        void operator++(int);

        unsigned long long getValue () const;
        unsigned long long operator*() const;

        int getValueAtIndex(int index);
        void jumpToIndex(int index);
};

#endif //FACTORIAL_ITERATOR_H
