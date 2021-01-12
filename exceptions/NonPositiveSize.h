#pragma once
#include <iostream>

class NonPositiveSize : std::exception {
public:
    explicit NonPositiveSize(int index);
};