#include <iostream>
#include "Iterator.h"

using namespace std;

int main() {
    NaturalIterator seq(22);

    for ( ; !seq.over(); seq++ ) {
        cout << *seq << ' ';
    }
    cout << *seq << endl;

    return 0;
}
