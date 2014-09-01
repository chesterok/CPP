#include <iostream>
#include "Iterator.h"

using namespace std;

int main() {
    APIterator seq(0,20,2);

    for ( ; !seq.over(); seq++ ) {
        cout << *seq << ' ';
    }
    cout << *seq << endl;

    return 0;
}
