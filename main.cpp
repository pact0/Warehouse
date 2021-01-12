#include "helperFun.h"
#include "basic_vector.h"

std::basic_istream<char> *input;

int readInt() {
    std::string line;
    std::getline(*input, line);
    return std::stoi(line);
}

double readDouble() {
    std::string line;
    std::getline(*input, line);
    return std::stod(line);
}

std::string readString() {
    std::string line;
    std::getline(*input, line);
    return line;
}

int main(int argc, char** argv) {
    //freopen(argv[1],"r",stdin);
//    LiquidProduct prod(0, "A", 10);
//    LiquidProduct prod2(1, "B", 10);
//    basic_vector<LiquidProduct> prod_vec(2);
//    //prod.printProduct();
//    prod_vec.push_back(prod);
//    prod_vec.push_back(prod2);
//
//
//    for (auto &item : prod_vec) {
//        std::cout<< item.fetchWeight() << '\n';
//        item.printProduct();
//    }
//
//    prod_vec.pop_back();
//
//    for (auto &item : prod_vec) {
//
//        std::cout<< item.fetchWeight() << "POOP" << '\n';
//        item.printProduct();
//    }
//    return 1;
    input = &std::cin;
    if ( argc ==2) {
        for (int i = 0; i < argc; ++i) {
            if ( i + 1 < argc) {
                auto file = new std::ifstream(argv[i + 1], std::ios_base::in);
                if (!file->is_open()) {
                    std::cerr << "No such file" << argv[i + 1] << std::endl;
                    return 1;
                }
                input = file;
            }
        }
    }
    basic_vector<Warehouse*> warehouses;
    basic_vector<PalletTruck*> palletTrucks;
    int choice;
    do {
        std::cout <<"\n---===== MENU =====---\n"
                    "0: Wychodzi z programu.\n"
                    "1: Zarzadzaj magazynami.\n"
                    "2: Zarzadzaj paleciakami.\n"
                    "3: Wypisz wszystkie magazyny.\n"
                    "4: Wypisz wszystkie paleciaki.\n"
                    "Wybierz akcje(0-4):";
        choice = readInt();
        std::cout <<'\n';
        switch (choice) {
            case 0:
                std::cout << "Koniec programu." << '\n';
                break;
            case 1:
                try {
                menuWarehouse(warehouses);
                }catch (const NoWarehouseException &){
                    break;
                }
                break;
            case 2:
                try {
                menuPalletTruck(warehouses, palletTrucks);
                } catch (const NoWarehouseException&) {
                }
                catch(const EmptyWarehouseException&) {
                }
                catch (const NoPalletTruckException&){
                }
                break;
            case 3:
                try {
                printWarehouses(warehouses);
                }catch (const NoWarehouseException&){

                }
                break;
            case 4:
                try{
                printPalletTrucks(palletTrucks);
                }catch (const NoPalletTruckException&){

                }
                break;
            default:
                std::cerr << "Podaj poprawna wartosc(0-4)!" << '\n';
        }
    }while(choice != 0);

    warehouses.clear();
    palletTrucks.clear();
}