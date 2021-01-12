#include "EmptyWarehouseException.h"

EmptyWarehouseException::EmptyWarehouseException() {
    std::cerr << "Magazyn jest pusty, najpierw dodaj jakies produkty w menu zarzadzania magazynami." << '\n';
}
