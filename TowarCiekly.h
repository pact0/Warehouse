#pragma once
#include "Produkt.h"

class TowarCiekly:public Produkt{
    std::string _name;
    double _amount;
public:
    TowarCiekly(int ID = -1, std::string name = "nieznany");
    double fetchAmount() const override { return _amount; };
    std::string fetchName() const override { return _name; };
    void printProduct() const override;
    double fetchWeight() const override { return _amount * 1; };

    double increaseAmount(double count) override;   // zwieksza ilosc o count, zwraca ilosc dodanych towarow
    double decreaseAmount(double count) override;   // zmniejsza ilosc o count, zwraca ilosc odebranych towarow
    double setAmount(double count) override;        // ustawia ilosc na count, zwraca na jaka wartosc ustawiono ilosc
    Produkt* split(double count) override;
    void merge(Produkt* product) override;
};