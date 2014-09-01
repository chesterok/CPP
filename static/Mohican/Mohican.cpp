#include "Mohican.h"

Mohican* Mohican::lastMohican = NULL;

Mohican::Mohican(std::string name) : name(name) {
    if ( lastMohican != NULL ) {
        prev = lastMohican;
        prev->next = this;
    }
    lastMohican = this;
}

Mohican::~Mohican() {
    if ( lastMohican == this ) {
        lastMohican = prev;
    }
    prev->next = next;
    next->prev = prev;
}

Mohican& Mohican::getLastMohican() {
    return *lastMohican;
}

const std::string& Mohican::getName() const {
    return name;
}
