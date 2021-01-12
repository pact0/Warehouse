#pragma once
#include <iostream>

class OutOfBoundsException : std::exception {
public:
    explicit OutOfBoundsException(int index);
};
