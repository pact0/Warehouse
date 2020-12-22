#pragma once
#include "Product.h"
#include "PalletTruck.h"
class Magazyn {
    std::vector<Product*> _products;
    static int _counter_ID;
    int _ID;
public:
    explicit Magazyn(int ID);
    ~Magazyn();
    
    enum class manipulateProducts{increase, decrease, set};
    static int fetchProductID() { return _counter_ID++;};
    int fetchProductAmount(int idx) const { return _products[idx]->fetchAmount(); };
    int fetchWarehouseID() const { return _ID;};
    int fetchID() const { return _ID; };
    int fetchProductCount() const { return _products.size(); };
    void printWarehouse();
    double fetchProductWeight(int idx) const { return _products[idx]->fetchWeight(); };

    int isEmpty() const { return _products.empty();};
    int findProductByID(int ID);
    void addProduct(Product* produkt);
    void changeProduct(int ID, double howMuch, manipulateProducts x);

    void wydaj(PalletTruck* palletTruck, int ID, int howMuch);
    void przyjmij(PalletTruck* palletTruck, int ID, int howMuch);

};