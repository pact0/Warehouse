#pragma once
#include <iostream>

class NoWarehouseException : std::exception {
public:
    NoWarehouseException();
};