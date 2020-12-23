#pragma once
#include "Product.h"
#include "PalletTruck.h"
class Warehouse {
    std::vector<Product*> _products;
    static int _productIDCounter;
    int _ID;
public:
    explicit Warehouse(int ID);
    ~Warehouse();

    enum class manipulateProducts{increase, decrease, set};
    int fetchProductID() { return _productIDCounter++;};

    double fetchProductWeight(int idx) const { return _products[idx]->fetchWeight(); };
    double fetchProductAmount(int idx) const { return _products[idx]->fetchAmount(); };
    int fetchProductCount() const { return _products.size(); };
    int isEmpty() const { return _products.empty();};
    int fetchWarehouseID() const { return _ID;};
    int fetchID() const { return _ID; };
    void printWarehouse();

    int findProductByID(int ID);
    void addProduct(Product* product);
    void sendProduct(PalletTruck* palletTruck, int ID, int howMuch);
    void collect(PalletTruck* palletTruck, int ID, int howMuch);
    void changeProduct(int ID, double howMuch, manipulateProducts x);

};