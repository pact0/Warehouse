#pragma once
#include "Produkt.h"

class Towar: public Produkt{
    std::string _name;
    int _amount;
public:
    Towar(int ID = -1, std::string name = "nieznany");
    double fetchAmount() const override { return _amount; };
    std::string fetchName() const override { return _name; };
    void printProduct() const override;


    double increaseAmount(double count) override;   // zwieksza ilosc o count, zwraca ilosc dodanych towarow
    double decreaseAmount(double count) override;   // zmniejsza ilosc o count, zwraca ilosc odebranych towarow
    double setAmount(double count) override;        // ustawia ilosc na count, zwraca na jaka wartosc ustawiono ilosc
};