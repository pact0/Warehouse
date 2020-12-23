#pragma once
#include "LiquidProduct.h"
#include "LooseProduct.h"
#include "UnitProduct.h"
#include "Warehouse.h"
#include <iostream>
#include <fstream>

void menuPalletTruck(std::vector<Warehouse*>& warehouses, std::vector<PalletTruck*>& palletTrucks);
void printPalletTrucks(std::vector<PalletTruck*>& palletTrucks);
void printWarehouses(std::vector<Warehouse*>& warehouses);
void menuWarehouse(std::vector<Warehouse*>& warehouses);
void menuProduct(std::vector<Warehouse*>& warehouses);
void dispense(Warehouse& warehouse);
void receive(Warehouse& warehouse);

int choosePalletTruck(std::vector<PalletTruck*> &palletTrucks);
int findWarehouse(std::vector<Warehouse*>& warehouses, int ID);
int chooseWarehouse(std::vector<Warehouse*>& warehouses);
int readInt();

double readDouble();

std::string readString();
