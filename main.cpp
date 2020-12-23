#include "helperFun.h"

std::basic_istream<char> *input;


int main(int argc, char** argv) {
    //freopen(argv[1],"r",stdin);

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
    std::vector<Warehouse*> warehouses;
    std::vector<PalletTruck*> palletTrucks;
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
                menuWarehouse(warehouses);
                break;
            case 2:
                menuPalletTruck(warehouses, palletTrucks);
                break;
            case 3:
                printWarehouses(warehouses);
                break;
            case 4:
                printPalletTrucks(palletTrucks);
                break;
            default:
                std::cerr << "Podaj poprawna wartosc(0-4)!" << '\n';
        }
    }while(choice != 0);

}



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

