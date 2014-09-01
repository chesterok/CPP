#include "Pen.h"

Pen::Pen(int inkCapacity) : inkCapacity(inkCapacity), inkAmount(inkCapacity) {}

Pen::~Pen() {}

int Pen::getInkAmount() const {
    return inkAmount;
}

int Pen::getInkCapacity() const {
    return inkCapacity;
}

void Pen::write(Paper& paper, const std::string& message) {
    if ( inkAmount == 0 ) {
        throw OutOfInk();
    }
    if ( message.length() > inkAmount ) {
        paper.addContent(message.substr(0, inkAmount));
        inkAmount = 0;
        return;
    }
    paper.addContent(message);
    inkAmount -= message.length();
}

void Pen::refill() {
    inkAmount = inkCapacity;
}
