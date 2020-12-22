#include "TowarCiekly.h"

TowarCiekly::TowarCiekly(int ID, std::string name, double weight) {
    Product::ID = ID;
    _weight = weight;
    _amount = 0;
    _name = name;
}

void TowarCiekly::printProduct() const {
    std::cout << std::left << std::setw(4) << Product::ID;
    std::cout << std::left << std::setw(32) << _name;
    std::cout << std::left << std::setw(20) << _weight;
    std::cout << std::left << _amount << '\n';
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

Product *TowarCiekly::split(double count) {
    this->_amount -= static_cast<int>(count);
    TowarCiekly* newTowar = new TowarCiekly(this->Product::ID, this->_name, this->_weight);
    newTowar->setAmount(count);
    return newTowar;
}

void TowarCiekly::merge(Product *product) {
    this->_amount += product->fetchAmount();
    delete product;
}
