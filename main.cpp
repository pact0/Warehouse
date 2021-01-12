#include "helperFun.h"

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
                    std::cout << "Czy chcesz teraz stworzyc magazyn?\n"
                                 "1: Tak.\n"
                                 "0: Nie, wroc do glownego menu." << '\n';
                    int temp = 0;
                    do {
                        temp = readInt();
                        if( temp == 1 ){
                            createWarehouse(warehouses);
                            break;
                        }
                    }while(temp != 0);
                }
                break;
            case 2:
                try {
                menuPalletTruck(warehouses, palletTrucks);
                }catch (const NoWarehouseException&) {
                    std::cout << "Czy chcesz teraz stworzyc magazyn?\n"
                                 "1: Tak.\n"
                                 "0: Nie, wroc do glownego menu." << '\n';
                    int temp = 0;
                    do {
                        temp = readInt();
                        if( temp == 1 ){
                            createWarehouse(warehouses);
                            break;
                        }
                    }while(temp != 0);
                }
                catch(const EmptyWarehouseException&) {
                    std::cout << "Wracam do glownego menu." << '\n';
                }
                catch (const NoPalletTruckException&){
                    std::cout << "Czy chcesz teraz stworzyc paleciak?\n"
                                 "1: Tak.\n"
                                 "0: Nie, wroc do glownego menu." << '\n';
                    int temp = 0;
                    do {
                        temp = readInt();
                        if( temp == 1 ){
                            createPalletTruck(palletTrucks);
                            break;
                        }
                    }while(temp != 0);
                }
                break;
            case 3:
                try {
                printWarehouses(warehouses);
                }catch (const NoWarehouseException&){
                    std::cout << "Czy chcesz teraz stworzyc magazyn?\n"
                                 "1: Tak.\n"
                                 "0: Nie, wroc do glownego menu." << '\n';
                    int temp = 0;
                    do {
                        temp = readInt();
                        if( temp == 1 ){
                            createWarehouse(warehouses);
                            break;
                        }
                    }while(temp != 0);

                }
                break;
            case 4:
                try{
                printPalletTrucks(palletTrucks);
                }catch (const NoPalletTruckException&){
                    std::cout << "Czy chcesz teraz stworzyc paleciak?\n"
                                 "1: Tak.\n"
                                 "0: Nie, wroc do glownego menu." << '\n';
                    int temp = 0;
                    do {
                        temp = readInt();
                        if( temp == 1 ){
                            createPalletTruck(palletTrucks);
                            break;
                        }
                    }while(temp != 0);
                }
                break;
            default:
                std::cerr << "Podaj poprawna wartosc(0-4)!" << '\n';
        }
    }while(choice != 0);

    warehouses.clear();
    palletTrucks.clear();
}

