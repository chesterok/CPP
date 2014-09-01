#include <iostream>
#include "Iterator.h"

using namespace std;

int main() {
    char array[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J' };
    ArrayIterator<char> seq(array, 10);

    for ( ; !seq.over(); seq++ ) {
        cout << *seq << ' ';
    }
    cout << *seq << endl;

    return 0;
}
