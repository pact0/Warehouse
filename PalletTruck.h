#pragma once
#include "Product.h"


class PalletTruck {
    std::vector<Product*> _products;
    int _ID;
    double _maximumLoad;
    double _currentLoad{};
public:
    explicit PalletTruck(double max);
    ~PalletTruck();

    std::string fetchProductName(int ID) const { return _products[ID]->fetchName();};
    double fetchMaximumLoad() const { return _maximumLoad; };
    double fetchCurrentLoad() const { return _currentLoad; };
    double fetchProductAmount(int ID) const { return _products[ID]->fetchAmount();};
    int fetchPalletID() const { return _ID;};
    void printPaleciak() const;

    int findProductByID(int ID);
    Product* unLoadProduct(int idx, int howMuch);
    void loadProduct(Product* product);
};