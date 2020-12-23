#include "LiquidProduct.h"

LiquidProduct::LiquidProduct(int ID, std::string name, double weight) {
    Product::ID = ID;
    _weight = weight;
    _amount = 0;
    _name = name;
}

void LiquidProduct::printProduct() const {
    std::cout << std::left << std::setw(4) << Product::ID;
    std::cout << std::left << std::setw(32) << _name;
    std::cout << std::left << std::setw(20) << _weight;
    std::cout << std::left << _amount << '\n';
}

double LiquidProduct::increaseAmount(double count) {
    _amount += count;
    return count;
}

double LiquidProduct::decreaseAmount(double count) {
    _amount -= count;
    return count;
}

double LiquidProduct::setAmount(double count) {
    _amount = count;
    return count;
}

Product *LiquidProduct::split(double count) {
    this->_amount -= static_cast<int>(count);
    LiquidProduct* newTowar = new LiquidProduct(this->Product::ID, this->_name, this->_weight);
    newTowar->setAmount(count);
    return newTowar;
}

void LiquidProduct::merge(Product *product) {
    this->_amount += product->fetchAmount();
    delete product;
}
