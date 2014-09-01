#ifndef FILE_ITERATOR_H
#define FILE_ITERATOR_H

#include <cstdlib>
#include <iostream>
#include <fstream>

class OutOfMemory {};

template <class Type>
class FileIterator {
    private:
        std::ifstream file;
        Type* pointer;
        size_t current;
        size_t sizeBuf;

    public:
        FileIterator(const char* fileName) : file(fileName), current(0), sizeBuf(100) {
            pointer = (Type*)malloc(sizeBuf*sizeof(Type));
            if ( file.is_open() ) {
                file >> *pointer;
            }
        }

        void next() {
            if ( over() ) {
                return;
            }

            if ( current == sizeBuf ) {
                sizeBuf += 1000;
                Type* newPointer = (Type*)realloc(pointer, sizeBuf*sizeof(Type));

                if ( newPointer == NULL ) {
                    throw OutOfMemory();
                }

                pointer = newPointer;
            }
            current += 1;
            file >> pointer[current];      
        }

        void previous() {
            if ( less() ) {
                return;
            }
            current -= 1;
        }

        void operator++() { next(); }

        void operator--() { previous(); }

        void operator--(int) { operator--(); }

        void operator++(int) { operator++(); }

        bool less() const {
            return current <= 0;
        }

        bool over() {
            return file.eof();
        }

        const Type& getValue() const {
            return pointer[current];
        }

        const Type& operator*() { return getValue(); }
};

#endif //FILE_ITERATOR_H
