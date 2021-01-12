#pragma once
#include "LiquidProduct.h"
#include "LooseProduct.h"
#include "UnitProduct.h"
#include "Warehouse.h"
#include <iostream>
#include <fstream>
#include "exceptions/NoWarehouseException.h"
#include "exceptions/NoPalletTruckException.h"
#include "exceptions/EmptyWarehouseException.h"

void menuPalletTruck(basic_vector<Warehouse*>& warehouses, basic_vector<PalletTruck*>& palletTrucks);
void printPalletTrucks(basic_vector<PalletTruck*>& palletTrucks);
void printWarehouses(basic_vector<Warehouse*>& warehouses);
void menuWarehouse(basic_vector<Warehouse*>& warehouses);
void menuProduct(basic_vector<Warehouse*>& warehouses);
void dispense(Warehouse& warehouse);
void receive(Warehouse& warehouse);

int choosePalletTruck(basic_vector<PalletTruck*> &palletTrucks);
int findWarehouse(basic_vector<Warehouse*>& warehouses, int ID);
int chooseWarehouse(basic_vector<Warehouse*>& warehouses);

int readInt();
double readDouble();

std::string readString();
