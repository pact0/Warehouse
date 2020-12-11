#pragma once
#include "Produkt.h"
#include "Paleciak.h"
class Magazyn {
    std::vector<Produkt*> _products;
    static int _counter_ID;
    int _ID;
public:
    int fetchID() const { return _ID; };
    void printWarehouse();
    Magazyn(int ID);
    ~Magazyn();
};