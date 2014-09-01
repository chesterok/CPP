#include <iostream>
#include "Iterator.h"

using namespace std;

int main() {
    GPIterator seq(1,2,5);

    for ( ; !seq.over(); seq++ ) {
        cout << *seq << ' ';
    }
    cout << *seq << endl;

    return 0;
}
