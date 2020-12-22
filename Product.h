#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


class Product {
protected:
    int ID{};

public:
    virtual std::string fetchName() const = 0;
    virtual int fetchID() const { return ID; };
    virtual double fetchAmount() const = 0;
    virtual double fetchWeight() const = 0;
    virtual void printProduct() const = 0;

    virtual double increaseAmount(double count) = 0;    // zwieksza ilosc o count, zwraca ilosc dodanych towarow
    virtual double decreaseAmount(double count) = 0;    // zmniejsza ilosc o count, zwraca ilosc odebranych towarow
    virtual double setAmount(double count) = 0;         // ustawia ilosc na count, zwraca na jaka wartosc ustawiono ilosc
    virtual Product* split(double count) = 0;           // wydziela nowy produkt o ilosci 'count' i go zwraca
    virtual void merge(Product* product) = 0;           // przylacza przekazywany produkt

};