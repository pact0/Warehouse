#include "Paleciak.h"

static int counter = 0;
Paleciak::Paleciak(int max) {
    _ID = counter++;
    _maximumLoad = max;
}

Paleciak::~Paleciak() {
    for (auto &item : _products)
        delete item;
    _products.clear();
}

void Paleciak::loadProduct(Produkt *product) {
    _currentLoad += product->fetchAmount()*product->fetchWeight();
    int idx = findProductByID(product->fetchID());
    if ( idx == -1 )
        _products.push_back(product);
    else
        _products[idx]->merge(product);
}

Produkt* Paleciak::unLoadProduct(int idx, int howMuch) {
    _currentLoad -= howMuch*+_products[idx]->fetchWeight();
    Produkt* newProduct =_products[idx]->split(howMuch);
    if( _products[idx]->fetchAmount() == 0) {
        delete _products[idx];
        _products.erase(_products.begin()+idx);
    }

    return newProduct;
}

int Paleciak::findProductByID(int ID) {
    for(int i = 0; i < _products.size(); ++i)
        if (_products[i]->fetchID() == ID) return i;
    return -1;
}

void Paleciak::printPaleciak() const {
    std::cout << "---------------PALECIAK ID_" <<  _ID << "-------------" << '\n';
    std::cout << "Maksymalny udzwig: " << _maximumLoad << '\n';
    std::cout << std::left << std::setw(4) << "ID";
    std::cout << std::left << std::setw(32) << "Nazwa";
    std::cout << std::left << std::setw(16) << "Ilosc" << '\n';
    for (auto& product : _products)
        product->printProduct();
}
