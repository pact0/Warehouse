#include "TowarSypki.h"

TowarSypki::TowarSypki(int ID, std::string name) {
    Produkt::ID = ID;
    _amount = 0;
    _name = name;
}

void TowarSypki::printProduct() const {
    std::cout << std::left << std::setw(4) << Produkt::ID;
    std::cout << std::left << std::setw(32) << _name;
    std::cout << std::left << _amount << " kg"<<'\n';
}

double TowarSypki::increaseAmount(double count) {
    _amount += count;
    return count;
}

double TowarSypki::decreaseAmount(double count) {
    _amount = count;
    return count;
}

double TowarSypki::setAmount(double count) {
    _amount = count;
    return count;
}

Produkt *TowarSypki::split(double count) {
    return nullptr;
}

void TowarSypki::merge(Produkt *product) {

}
