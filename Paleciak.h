#pragma once
#include "Produkt.h"

class Paleciak {
    std::vector<Produkt*> _products;
    double _maximumLoad;
public:
    Paleciak();
    ~Paleciak();
};