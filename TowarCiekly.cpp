#include "TowarCiekly.h"

TowarCiekly::TowarCiekly(int ID, std::string name) {
    Produkt::ID = ID;
    _amount = 0;
    _name = name;
}

void TowarCiekly::printProduct() const {
    std::cout << std::left << std::setw(4) << Produkt::ID;
    std::cout << std::left << std::setw(32) << _name;
    std::cout << std::left << _amount <<  " l" << '\n';
}

double TowarCiekly::increaseAmount(double count) {
    _amount += count;
    return count;
}

double TowarCiekly::decreaseAmount(double count) {
    _amount -= count;
    return count;
}

double TowarCiekly::setAmount(double count) {
    _amount = count;
    return count;
}

Produkt *TowarCiekly::split(double count) {
    return nullptr;
}

void TowarCiekly::merge(Produkt *product) {

}
