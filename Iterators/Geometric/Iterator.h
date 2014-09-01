#ifndef G_P_ITERATOR_H
#define G_P_ITERATOR_H

#include <iostream>
#include <cmath>

class InvalidIndex{};
class InvalidMultiplier{};
class InvalidFirst{};

class GPIterator {
private:
    int first;
    int multiplier;
    int quantity;
    int value;
    int currentIndex;

public:
    GPIterator(int first=1, int multiplier=2, int quantity=3);

    bool over() const;
    bool less() const;
    void next();
    void previous();
    void reset();
    void jumpToIndex(int index);

    void operator++();
    void operator--();
    void operator--(int);
    void operator++(int);
    int operator*() const;

    int getValue() const;
    int getValueAtIndex(int index);
};

#endif //G_P_ITERATOR_H
