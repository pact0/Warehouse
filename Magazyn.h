#pragma once
#include "Produkt.h"
#include "Paleciak.h"
class Magazyn {
    std::vector<Produkt*> _products;
    static int _counter_ID;
    int _ID;
public:
    static int fetchProductID() { return _counter_ID++;};
    int fetchID() const { return _ID; };
    void printWarehouse();
    void addProduct(Produkt* produkt);
    Magazyn(int ID);
    ~Magazyn();
};