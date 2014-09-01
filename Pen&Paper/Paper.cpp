#include "Paper.h"

Paper::Paper(int maxSymbols) : maxSymbols(maxSymbols), symbols(0) {}

Paper::~Paper() {}

int Paper::getMaxSymbols() const {
    return maxSymbols;
}

int Paper::getSymbols() const {
    return symbols;
}

void Paper::addContent(const std::string& message) {
    int total = symbols + message.length();

    if ( maxSymbols == 0 ) {
        throw OutOfSpace();
    }
    if ( total > maxSymbols ) {
        content += message.substr(0, maxSymbols);
        symbols += maxSymbols;
        maxSymbols = 0;
        throw OutOfSpace();
    }
    content += message;
    maxSymbols -= message.size();
    symbols += message.size();
}

void Paper::show() const {
    std::cout << content << std::endl;
}
