#include "Paleciak.h"

Paleciak::Paleciak(int max) {
    _maximumLoad = max;
}

Paleciak::~Paleciak() {
    for (auto &item : _products)
        delete item;
}

void Paleciak::loadProduct(Produkt *product) {
    _currentLoad += product->fetchAmount();
    _products.push_back(product);
}

void Paleciak::unLoadProduct(int idx, int howMuch) {
    _currentLoad -= howMuch;
    _products[idx]->split(howMuch);
    if( _products[idx]->fetchAmount() == 0) delete _products[idx];
}

int Paleciak::findProductByID(int ID) {
    for(int i = 0; i < _products.size(); ++i)
        if (_products[i]->fetchID() == ID) return i;
    return -1;
}

void Paleciak::printPaleciak() const {
    std::cout << "---------------PALECIAK-------------" << '\n';
    std::cout << std::left << std::setw(4) << "ID";
    std::cout << std::left << std::setw(32) << "Nazwa";
    std::cout << std::left << std::setw(16) << "Ilosc" << '\n';
    for (auto& product : _products)
        product->printProduct();
}
