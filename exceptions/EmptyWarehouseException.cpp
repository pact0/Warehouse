#include "EmptyWarehouseException.h"

EmptyWarehouseException::EmptyWarehouseException() {
    std::cerr << "Empty warehouse." << '\n';
}
