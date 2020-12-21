#pragma once
#include "Produkt.h"


class Paleciak {
    std::vector<Produkt*> _products;
    int _ID;
    double _maximumLoad;
    double _currentLoad;
public:
    int findProductByID(int ID);
    double fetchMaximumLoad() const { return _maximumLoad; };
    double fetchCurrentLoad() const { return _currentLoad; };
    double fetchProductAmount(int ID) const { return _products[ID]->fetchAmount();};
    std::string fetchProductName(int ID) const { return _products[ID]->fetchName();};
    void printPaleciak() const;
    void loadProduct(Produkt* product);
    Produkt* unLoadProduct(int idx, int howMuch);
    Paleciak(int max);
    ~Paleciak();
};