#include "Magazyn.h"

int Magazyn::_counter_ID = 0;

void Magazyn::printWarehouse() {
    std::cout << "---------------MAGAZYN ID_"<< _ID << "-------------" << '\n';
    std::cout << std::left << std::setw(4) << "ID";
    std::cout << std::left << std::setw(32) << "Nazwa";
    std::cout << std::left << std::setw(16) << "Waga jednego";
    std::cout << std::left << std::setw(16) << "Ilosc" << '\n';
    for( auto& item: _products) {
        item->printProduct();
    }
    std::cout << '\n';
}

void Magazyn::addProduct(Product *produkt) {
    _products.push_back(produkt);
}

Magazyn::Magazyn(int ID) {
    _ID = ID;
}

Magazyn::~Magazyn() {
    for (auto &product :_products)
        delete product;
    _products.clear();
}

void Magazyn::changeProduct(int ID, double howMuch, Magazyn::manipulateProducts x) {
    if( x == manipulateProducts::increase )
        _products[ID]->decreaseAmount(howMuch);
    else if(x == manipulateProducts::decrease)
        _products[ID]->increaseAmount(howMuch);
    else
        _products[ID]->setAmount(howMuch);
}

int Magazyn::findProductByID(int ID) {
    for(int i = 0; i < _products.size(); ++i)
        if (_products[i]->fetchID() == ID) return i;
    return -1;
}

void Magazyn::wydaj(PalletTruck* palletTruck, int ID, int howMuch) {
    int idx = findProductByID(ID);
    palletTruck->loadProduct(_products[idx]->split(howMuch));
}

void Magazyn::przyjmij(PalletTruck* palletTruck, int ID, int howMuch) {
    int idx = this->findProductByID(ID);
    int idx_p = palletTruck->findProductByID(ID);
    if ( idx == -1 )
        this->addProduct(palletTruck->unLoadProduct(idx_p, howMuch));
    else{
    _products[idx]->increaseAmount(howMuch);
    palletTruck->unLoadProduct(idx_p, howMuch);
    }
}