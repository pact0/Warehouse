#pragma once


class OutOfBoundsException :: std::exception {
public:
    explicit OutOfBoundsException(int index);
};
