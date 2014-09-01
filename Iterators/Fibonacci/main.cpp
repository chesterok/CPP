#include <iostream>
#include "Iterator.h"

using namespace std;

int main() {
    FibonacciIterator seq(-10, 10);

    for ( ; !seq.over(); seq++ ) {
        cout << *seq << ' ';
    }
    cout << *seq << endl;

    return 0;
}
