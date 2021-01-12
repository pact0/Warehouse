#include "OutOfBoundsException.h"

OutOfBoundsException::OutOfBoundsException(int index) {
    std::cerr << "Wrong index: " << index << '\n';
}
