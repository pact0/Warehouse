#pragma once
#include "Product.h"

class LooseProduct: public Product{
    std::string _name;
    double _amount;
    double _weight;
public:
    explicit LooseProduct(int ID = -1, std::string name = "nieznany", double weight = 1);

    std::string fetchName() const override { return _name; };
    double fetchAmount() const override { return _amount; };
    double fetchWeight() const override { return _weight; };
    void printProduct() const override;

    double increaseAmount(double count) override;   // zwieksza ilosc o count, zwraca ilosc dodanych towarow
    double decreaseAmount(double count) override;   // zmniejsza ilosc o count, zwraca ilosc odebranych towarow
    double setAmount(double count) override;        // ustawia ilosc na count, zwraca na jaka wartosc ustawiono ilosc
    Product* split(double count) override;
    void merge(Product* product) override;
};