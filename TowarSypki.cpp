#include "TowarSypki.h"

//#include <utility>

TowarSypki::TowarSypki(int ID, std::string name, double weight) {
    Product::ID = ID;
    _weight = weight;
    _amount = 0;
    _name = std::move(name);
}

void TowarSypki::printProduct() const {
    std::cout << std::left << std::setw(4) << Product::ID;
    std::cout << std::left << std::setw(32) << _name;
    std::cout << std::left << std::setw(20) << _weight;
    std::cout << std::left << _amount <<'\n';
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

Product *TowarSypki::split(double count) {
    this->_amount -= static_cast<int>(count);
    auto* newTowar = new TowarSypki(this->Product::ID, this->_name, this->_weight);
    newTowar->setAmount(count);
    return newTowar;
}

void TowarSypki::merge(Product *product) {
    this->_amount += product->fetchAmount();
    delete product;
}
