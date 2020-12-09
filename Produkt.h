#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


class Produkt {
protected:
    int ID;
    virtual void ustawID(int ID)  = 0;
public:
    virtual int zwrocID() const { return ID; };
    virtual double zwrocIlosc() const = 0;
    virtual std::string zwrocNazwe() const = 0; //funkcja abstrakcyjna
    virtual void wypiszTowar() const = 0;


    virtual double zwiekszIlosc(double count) = 0;    // zwieksza ilosc o count, zwraca ilosc dodanych towarow
    virtual double zmniejszIlosc(double count) = 0;   // zmniejsza ilosc o count, zwraca ilosc odebranych towarow
    virtual double ustawIlosc(double count) = 0;      // ustawia ilosc na count, zwraca na jaka wartosc ustawiono ilosc


};