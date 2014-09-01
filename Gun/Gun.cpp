#include "Gun.h"

Gun::Gun(const std::string& model, int capacity) : model(model)
                                              , capacity(capacity)
                                              , amount(0)
                                              , isReady(false)
                                              , totalShots(0) {}

Gun::~Gun() {}

int Gun::getAmount() const {
    return amount;
}

int Gun::getCapacity() const {
    return capacity;
}

bool Gun::ready() const {
    return isReady;
}

const std::string& Gun::getModel() const {
    return model;
}

int Gun::getTotalShots() const {
    return totalShots;
}

void Gun::prepare() {
    isReady = !isReady;
}

void Gun::reload() {
    amount = capacity;
}

void Gun::shoot() {
    if ( !ready() ) {
        throw NotReady();
    }
    if ( amount == 0 ) {
        throw OutOfRounds();
    }
    std::cout << "Bang!" << std::endl;
    amount -= 1;
    totalShots += 1;
}

std::ostream& operator<<(std::ostream& out, const Gun& gun) {
    out << "Gun \"" << gun.getModel() << "\" :" << std::endl;
    out << "-- amount: " << gun.getAmount() << std::endl;
    out << "-- capacity: " << gun.getCapacity() << std::endl;
    out << "-- totalShots: " << gun.getTotalShots() << std::endl;

   return out;
}
