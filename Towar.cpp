#include "Towar.h"

Towar::Towar(int ID,  std::string name) {
    Produkt::ID = ID;
    _amount = 0;
    _name = name;
}

void Towar::printProduct() const {
    std::cout << std::left << std::setw(4) << Produkt::ID;
    std::cout << std::left << std::setw(32) << _name;
    std::cout << std::left << std::setw(16) << _amount << '\n';
}

double Towar::increaseAmount(double count) {
    _amount += static_cast<int>(count);
    return count;
}


double Towar::decreaseAmount(double count) {
    _amount -=static_cast<int>(count);
    return count;}

double Towar::setAmount(double count) {
    _amount = static_cast<int>(count);
    return count;}
