#include "Warehouse.h"

int Warehouse::_productIDCounter = 0;


Warehouse::Warehouse(int ID) {
    _ID = ID;
}

Warehouse::~Warehouse() {
    for (auto &product :_products)
        delete product;
    _products.clear();
}

void Warehouse::printWarehouse() {
    std::cout << "-------------------------MAGAZYN ID_"<< _ID << "-----------------------" << '\n';
    std::cout << std::left << std::setw(4) << "ID";
    std::cout << std::left << std::setw(32) << "Nazwa";
    std::cout << std::left << std::setw(20) << "Waga jednego[kg]";
    std::cout << std::left << std::setw(16) << "Ilosc" << '\n';
    for( auto& item: _products) {
        item->printProduct();
    }
}

void Warehouse::addProduct(Product *product) {
    _products.push_back(product);
}

void Warehouse::changeProduct(int ID, double howMuch, Warehouse::manipulateProducts x) {
    if( x == manipulateProducts::increase )
        _products[ID]->decreaseAmount(howMuch);
    else if(x == manipulateProducts::decrease)
        _products[ID]->increaseAmount(howMuch);
    else
        _products[ID]->setAmount(howMuch);
}

int Warehouse::findProductByID(int ID) {
    for(int i = 0; i < _products.size(); ++i)
        if (_products[i]->fetchID() == ID) return i;
    return -1;
}

void Warehouse::sendProduct(PalletTruck* palletTruck, int ID, int howMuch) {
    int idx = findProductByID(ID);
    palletTruck->loadProduct(_products[idx]->split(howMuch));
}

void Warehouse::collect(PalletTruck* palletTruck, int ID, int howMuch) {
    int idx = this->findProductByID(ID);
    int idx_p = palletTruck->findProductByID(ID);
    if ( idx == -1 )
        this->addProduct(palletTruck->unLoadProduct(idx_p, howMuch));
    else
        {
    _products[idx]->increaseAmount(howMuch);
    palletTruck->unLoadProduct(idx_p, howMuch);
    }
}
