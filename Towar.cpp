#include "Towar.h"

Towar::Towar(int ID,  std::string name, double weight) {
    Product::ID = ID;
    _amount = 0;
    _name = name;
    _weight = weight;
}

void Towar::printProduct() const {
    std::cout << std::left << std::setw(4) << Product::ID;
    std::cout << std::left << std::setw(32) << _name;
    std::cout << std::left << std::setw(20) << _weight;
    std::cout << std::left  << _amount << '\n';
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
    return count;
}

Product *Towar::split(double count) {
    this->_amount -= static_cast<int>(count);
    auto* newTowar = new Towar(this->Product::ID, this->_name, this->_weight);
    newTowar->setAmount(count);
    return newTowar;
}

void Towar::merge(Product *product) {
    this->_amount += static_cast<int>(product->fetchAmount());
    delete product;
}
