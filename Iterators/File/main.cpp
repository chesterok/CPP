#include <iostream>
#include "Iterator.h"

using namespace std;

int main() {
    FileIterator<int> seq("task.in");

    for ( ; !seq.over(); seq++ ) {
        cout << *seq << ' ';
    }
    cout << *seq << endl;

    for ( ; !seq.less(); seq-- ) {
        cout << *seq << ' ';
    }
    cout << *seq << endl;

    return 0;
}
