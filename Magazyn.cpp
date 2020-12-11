#include "Magazyn.h"

int Magazyn::_counter_ID = 0;

void Magazyn::printWarehouse() {
    std::cout << "---------------MAGAZYN_"<< _ID << "-------------" << '\n';
    std::cout << std::left << std::setw(4) << "ID";
    std::cout << std::left << std::setw(32) << "Nazwa";
    std::cout << std::left << std::setw(16) << "Ilosc" << '\n';
    for( auto& item: _products) {
        item->printProduct();
    }

}

void Magazyn::addProduct(Produkt *produkt) {
    _products.emplace_back(produkt);
}

Magazyn::Magazyn(int ID) {
    _ID = ID;
}

Magazyn::~Magazyn() {

}
