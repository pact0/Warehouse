#include "Magazyn.h"

void Magazyn::printWarehouse() {
    std::cout << "---------------MAGAZYN"<< _ID << "-------------" << '\n';
    std::cout << std::left << std::setw(4) << "ID";
    std::cout << std::left << std::setw(32) << "Nazwa";
    std::cout << std::left << std::setw(16) << "Ilosc" << '\n';
    for( auto& item: _products) {
        //item->wypiszTowar();
    }

}

Magazyn::Magazyn(int ID) {

}

Magazyn::~Magazyn() {

}
