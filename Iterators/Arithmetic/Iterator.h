#ifndef A_P_ITERATOR_H
#define A_P_ITERATOR_H

#include <iostream>

class InvalidIndex {};
class InvalidParam {};

class APIterator {
    private:
        int first;
        int last;
        int step;
        int value;

    public:
        APIterator(int first=0, int last=20, int step=2);

        void next();
        void previous();
        bool less();
        bool over();

        void operator--();
        void operator--(int);
        void operator++();
        void operator++(int);
        int operator*();

        void reset();
        void jumpToIndex(int index);
        int getValueAtIndex(int index);
        int getValue() const;
};

#endif //A_P_ITERATOR_H
