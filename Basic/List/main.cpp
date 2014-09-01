#include <iostream>
#include "List.h"

int main() {
    List* lst = new List;

    std::cout << "List created at: " << &lst << std::endl;

    std::cout << "push_back 10 elems: ";
    for ( int i = 0; i < 10; i++ ) {
        lst->push_back(10*i);
    }
    std::cout << *lst << std::endl;

    std::cout << "erase 5 index: ";
    lst->erase(5);
    std::cout << *lst << std::endl;

    std::cout << "insert 789, to index 5: ";
    lst->insert(789,5);
    std::cout << *lst << std::endl;

    std::cout << "sort: ";
    lst->sort();
    std::cout << *lst << std::endl;

    std::cout << "find 789: " << std::endl;
    std::cout << "element is located on index: " << lst->find(789) << std::endl;

    std::cout << "pop_back: ";
    lst->pop_back();
    std::cout << *lst << std::endl;

    delete lst;

    return 0;
}
