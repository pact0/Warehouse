#pragma once
#include <iostream>

class NoPalletTruckException : std::exception {
public:
    NoPalletTruckException();
};