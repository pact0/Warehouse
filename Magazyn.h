#pragma once
#include "Produkt.h"
#include "Paleciak.h"
class Magazyn {
    std::vector<Produkt*> _products;
    static int _counter_ID;
    int _ID;
public:

    enum class manipulateProducts{increase, decrease, set};
    static int fetchProductID() { return _counter_ID++;};
    int fetchProductAmount(int idx) const { return _products[idx]->fetchAmount(); };
    double fetchProductWeight(int idx) const { return _products[idx]->fetchWeight(); };
    int fetchID() const { return _ID; };
    int fetchProductCount() const { return _products.size(); };
    void printWarehouse();
    void addProduct(Produkt* produkt);
    void changeProduct(int ID, double howMuch, manipulateProducts x);
    int findProductByID(int ID);

    void wydaj(Paleciak* paleciak, int ID, int howMuch);
    void przyjmij(Paleciak* paleciak, int ID, int howMuch);
    Magazyn(int ID);
    ~Magazyn();
};