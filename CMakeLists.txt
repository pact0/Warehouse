cmake_minimum_required(VERSION 3.17)
project(Warehouse)

set(CMAKE_CXX_STANDARD 14)

add_executable(Warehouse main.cpp Product.h Product.cpp PalletTruck.h Warehouse.h Warehouse.cpp PalletTruck.cpp Towar.h TowarSypki.h TowarCiekly.h Towar.cpp TowarSypki.cpp TowarCiekly.cpp)