#pragma once
#include <iostream>

class EmptyWarehouseException : std::exception {
public:
    EmptyWarehouseException();
};