#include "Identifiable.h"

int Identifiable::lastId = 0;

Identifiable::Identifiable() {
    lastId += 1;
    id = lastId;
}

Identifiable::~Identifiable() {}

int Identifiable::getId() {
    return id;
}
