#ifndef NATURAL_ITERATOR_H
#define NATURAL_ITERATOR_H

#include <iostream>
#include <cstdlib>
#include <cmath>

class OutOfMemory{};
class InvalidIndex{};

class NaturalIterator {
    private:
        int* pointer;
        int limit;
        int current;
        int maxSize;
    
    public:
        NaturalIterator(int limit=20);
        
        void next();
        void previous();
        void reset();
        bool less() const;
        bool over() const;

        void jumpToIndex(int index);
        int getValueAtIndex(int index);
        int getValue() const;

        const int operator[](int index) const;
        void operator--();
        void operator--(int);
        void operator++();
        void operator++(int);
        int operator*();

};

#endif // NATURAL_ITERATOR_H
