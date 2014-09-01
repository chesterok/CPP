#ifndef TEMPLATES_CPP
#define TEMPLATES_CPP

#include <iostream>
#include <set>
#include <map>

template <typename Type>
std::ostream& operator<<(std::ostream& out, const std::set<Type>& lst) {
    typename std::set<Type>::iterator it = lst.begin();

    if ( lst.size() == 0 ) {
        out << "\nempty ^_^ \n";
    } else {
        out << "[";
        for ( int i = lst.size() ; i > 1 ; it++, i-- ) {
            out << (*it)->getName() << ", ";
        }
        out << (*it)->getName() << "]";
    }
    return out;
}

template <typename First, typename Second>
std::ostream& operator<<(std::ostream& out, const std::map<First, Second>& lst) {
    typename std::map<First, Second>::const_iterator it = lst.begin();

    for ( ; it != lst.end(); it++ ) {
        out << it->first->getName() << " : " << it->second << " items;" << std::endl;
    }
    return out;
}


#endif // TEMPLATES_CPP
