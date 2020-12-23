#include "LooseProduct.h"

//#include <utility>

LooseProduct::LooseProduct(int ID, std::string name, double weight) {
    Product::ID = ID;
    _weight = weight;
    _amount = 0;
    _name = std::move(name);
}

void LooseProduct::printProduct() const {
    std::cout << std::left << std::setw(4) << Product::ID;
    std::cout << std::left << std::setw(32) << _name;
    std::cout << std::left << std::setw(20) << _weight;
    std::cout << std::left << _amount <<'\n';
}

double LooseProduct::increaseAmount(double count) {
    _amount += count;
    return count;
}

double LooseProduct::decreaseAmount(double count) {
    _amount = count;
    return count;
}

double LooseProduct::setAmount(double count) {
    _amount = count;
    return count;
}

Product *LooseProduct::split(double count) {
    this->_amount -= static_cast<int>(count);
    auto* newTowar = new LooseProduct(this->Product::ID, this->_name, this->_weight);
    newTowar->setAmount(count);
    return newTowar;
}

void LooseProduct::merge(Product *product) {
    this->_amount += product->fetchAmount();
    delete product;
}
