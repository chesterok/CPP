#ifndef ARRAY_ITERATOR_H
#define ARRAY_ITERATOR_H

#include <iostream>

class InvalidIndex {};

template <class Type>
class ArrayIterator {
    private:
        Type* array;
        size_t last;
        size_t current;

    public:
        ArrayIterator(Type* pointer, size_t size) : last(size - 1), current(0), array(pointer) {}

        void next() {
            if ( over() ) {
                return;
            }
            current += 1;
        }

        void previous() {
            if ( less() ) {
                return;
            }
            current -= 1;
        }

        void reset() {
            current = 0;
        }

        void operator++() {
            next();
        }

        void operator++(int) {
            operator++();
        }

        void operator--() {
            previous();
        }

        void operator--(int) {
            operator--();
        }

        bool over() const {
            return current >= last;
        }

        bool less() const { 
            return current <= 0;
        }

        const Type& value() const { 
            return array[current];
        }

        const Type& getValueAtIndex(size_t index) const {
            if ( index > last ) {
                throw InvalidIndex();
            }

            return array[index];
        }

        void jumpToIndex(size_t index) {
            getValueAtIndex(index);
            current = index;
        }

        const Type& operator*() const { return value(); }
};

#endif //ARRAY_ITERATOR_H
