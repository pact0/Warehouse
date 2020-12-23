#include "UnitProduct.h"

#include <utility>

UnitProduct::UnitProduct(int ID, std::string name, double weight) {
    Product::ID = ID;
    _amount = 0;
    _name = std::move(name);
    _weight = weight;
}

void UnitProduct::printProduct() const {
    std::cout << std::left << std::setw(4) << Product::ID;
    std::cout << std::left << std::setw(32) << _name;
    std::cout << std::left << std::setw(20) << _weight;
    std::cout << std::left  << _amount << '\n';
}

double UnitProduct::increaseAmount(double count) {
    _amount += static_cast<int>(count);
    return count;
}


double UnitProduct::decreaseAmount(double count) {
    _amount -=static_cast<int>(count);
    return count;}

double UnitProduct::setAmount(double count) {
    _amount = static_cast<int>(count);
    return count;
}

Product *UnitProduct::split(double count) {
    this->_amount -= static_cast<int>(count);
    auto* newTowar = new UnitProduct(this->Product::ID, this->_name, this->_weight);
    newTowar->setAmount(count);
    return newTowar;
}

void UnitProduct::merge(Product *product) {
    this->_amount += static_cast<int>(product->fetchAmount());
    delete product;
}
