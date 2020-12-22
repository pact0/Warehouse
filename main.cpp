#include "Warehouse.h"
#include "TowarCiekly.h"
#include "Towar.h"
#include "TowarSypki.h"

void menuMagazyn(std::vector<Warehouse>& warehouses);
void menuProdukt(std::vector<Warehouse>& warehouses);
void menuPaleciak(std::vector<Warehouse>& warehouses, std::vector<PalletTruck>& palletTrucks);
void printWarehouses(std::vector<Warehouse>& warehouses);
int chooseWarehouse(std::vector<Warehouse>& warehouses);
void printPalletTrucks(std::vector<PalletTruck>& palletTrucks);
int findWarehouse(std::vector<Warehouse>& warehouses, int ID);
void receive(Warehouse& warehouse);
void dispense(Warehouse& warehouse);

std::string readString();
int readInt();

int main() {
    std::vector<Warehouse> warehouses;
    std::vector<PalletTruck> palletTrucks;
    int choice = 0;

    do {
        std::cout <<"\n---====== MENU =====---\n"
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
                menuMagazyn(warehouses);
                break;
            case 2:
                menuPaleciak(warehouses, palletTrucks);
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
    std::getline(std::cin, line);
    return atoi(line.c_str());
}

double readDouble() {
    std::string line;
    std::getline(std::cin, line);
    return atof(line.c_str());
}

std::string readString() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

void menuProdukt(std::vector<Warehouse>& warehouses){
    int choice = 0;
    if(warehouses.empty() ){
        std::cerr << "Najpierw stworz magazyn!\n";
        return;
    }
    int which = chooseWarehouse(warehouses);
    std::string name;
    do {
        std::cout <<"\n---====== MENU =====---\n"
                    "0: Wychodzi z menu zarzadzania produktami.\n"
                    "1: Stworz produkt.\n"
                    "2: Zmien produkt.\n"
                    "3: Wypisz produkty.\n"
                    "4: Zmien magazyn.\n"
                    "Wybierz akcje(0-4):";
        choice = readInt();
        std::cout <<'\n';
        switch ( choice ) {
            case 0:
                std::cout << "Wracam do menu.\n";
                break;
            case 1:
                std::cout <<"Jaki typ prduktu chcesz stworzyc?\n"
                            "0: Towar.\n"
                            "1: Towar Sypki.\n"
                            "2: Towar Ciekly.\n"
                            "Wybierz akcje(0-2):";
                switch ( readInt() ) {
                    case 0:
                        std::cout << "Podaj nazwe produktu.\n";
                        name = readString();
                        std::cout << "Podaj wage pojedynczego produktu w kg.\n";
                        warehouses[which].addProduct(new Towar(warehouses[which].fetchProductID(),  name, readDouble()));
                        break;
                    case 1:
                        std::cout << "Podaj nazwe produktu.\n";
                        warehouses[which].addProduct(new TowarSypki(warehouses[which].fetchProductID(), readString()));
                        break;
                    case 2:
                        std::cout << "Podaj nazwe produktu.\n";
                        name = readString();
                        std::cout << "Podaj wage jednego litra produktu w kg.\n";
                        warehouses[which].addProduct(new TowarCiekly(warehouses[which].fetchProductID(), name, readDouble() ));
                        break;
                    default :
                        std::cerr << "Podaj poprawna wartosc(0-2)!" << '\n';
                }
                break;
            case 2:
                std::cout <<"Co chcesz zrobic z towarami?\n"
                            "0: Wroc do poprzedniego menu.\n"
                            "1: Dodaj towar.\n"
                            "2: Odejmij towar.\n"
                            "3: Wypisz magazyn.\n"
                            "Wybierz akcje(0-3):";

                switch ( readInt() ) {
                    case 0:
                        break;
                    case 1:
                        if (warehouses[which].fetchProductCount() > 0)
                            receive(warehouses[which]);
                        else
                            std::cerr << "\nNajpierw dodaj towar!" << '\n';
                        break;

                    case 2:
                        if (warehouses[which].fetchProductCount() > 0)
                            dispense(warehouses[which]);
                        else
                            std::cerr << "Najpierw dodaj towar!" << '\n';
                        break;
                    case 3:
                        warehouses[which].printWarehouse();
                        break;
                    default :
                        std::cerr << "Podaj poprawna wartosc()!" << '\n';
                }
            case 3:
                warehouses[which].printWarehouse();
                break;
            case 4:
                chooseWarehouse(warehouses);
                break;
            default :
                std::cerr << "Podaj poprawna wartosc(0-4)!" << '\n';
        }
    }while(choice != 0);

}

void menuMagazyn(std::vector<Warehouse>& warehouses){
    int choice = 0;
    static int warehouseID = 0;
    int i;
    int index;
    do {
        std::cout <<"\n---====== MENU =====---\n"
                    "0: Wychodzi z menu zarzadzania magazynami.\n"
                    "1: Utworz magazyn.\n"
                    "2: Zarzadzaj produktami w magazynie.\n"
                    "3: Wypisz magazyn.\n"
                    "Wybierz akcje:";
        choice = readInt();
        switch (choice) {
            case 0:
                std::cout << "Wracam do menu.\n";
                break;
            case 1:
                std::cout << "Tworze magazyn.\n";
                warehouses.emplace_back(warehouseID++);
                break;
            case 2:
                menuProdukt(warehouses);
                break;
            case 3:
                if(warehouses.empty() ){
                    std::cerr << "Najpierw stworz magazyn!\n";
                    break;
                }
                std::cout << "Ktory magazyn chcesz wypisac?\n" << "Dostepne ID:" << '\n';
                for (auto & warehouse : warehouses){
                    std::cout << warehouse.fetchID() << "  ";
                }
                std::cout << "Podaj ID: ";
                i = readInt();
                std::cout << '\n';
                index = findWarehouse(warehouses, i);
                if (index == -1)
                    std::cerr << "Nie udalo sie znalezc magazynu z takim ID.\n";
                else
                    warehouses[index].printWarehouse();
                break;
            default :
                std::cerr << "Podaj poprawna wartosc(0-2)!" << '\n';
        }
    }while(choice != 0);
}

void menuPaleciak(std::vector<Warehouse>& warehouses, std::vector<PalletTruck>& palletTrucks){
    int choice = 0;
    int i = 0;
    int ID;
    int which = 0;
    int howMany;
    double howMuch;
    do {
        std::cout << "\n---====== MENU =====---\n"
                     "0: Wychodzi z menu zarzadzania paleciakami.\n"
                     "1: Utworz paleciak.\n"
                     "2: Wypisz paleciaki.\n"
                     "3: Zaladuj paleciak.\n"
                     "4: Rozladuj paleciak.\n"
                     "Wybierz akcje:";
        choice = readInt();
        switch (choice) {
            case 0:
                std::cout << "Wychodze z menu.\n";
                break;
            case 1:
                do {
                    std::cout << "Podaj maksymalny udzwig w kg.\n";
                    howMuch = readDouble();
                }while(howMuch <= 0 && ( std::cerr << "Podaj odpowiednia wartosc(wieksza od 0)!" << '\n', 1) );
                palletTrucks.emplace_back(howMuch);
                break;
            case 2:
                printPalletTrucks(palletTrucks);
                break;
            case 3:
                if(warehouses.empty() ){
                    std::cerr << "Najpierw stworz magazyn!\n";
                    break;
                }
                which = chooseWarehouse(warehouses);
                if( warehouses[which].isEmpty() ) {
                    std::cerr << "Magazyn jest pusty, najpierw dodaj tam produkty.\n";
                    break;
                }
                std::cout << "Ktory paleciak zaladowac?\n";
                printPalletTrucks(palletTrucks);
                std::cout << "Podaj ID: ";
                i = readInt();
                std::cout << "\nWybierz produkt.\n";
                warehouses[which].printWarehouse();
                std::cout << "Podaj ID: ";
                ID = readInt();
                std::cout << '\n';

                do {
                    std::cout << "Ile chcesz zaladowac?\n" << "Dostepna ilosc produktu: " << warehouses[which].fetchProductAmount(warehouses[which].findProductByID(ID))
                    << " Kazdy produkt wazy " << warehouses[which].fetchProductWeight(warehouses[which].findProductByID(ID)) << "kg" << '\n';
                    std::cout << "Podaj w sztukach: ";
                    howMany = readInt();
                    howMuch = howMany *  warehouses[which].fetchProductWeight(warehouses[which].findProductByID(ID));
                    std::cout << "\nProbuje zaladowac " << howMuch << "kg produktu." << '\n';

                    if( howMany < 0 || palletTrucks[i].fetchMaximumLoad()  < howMuch  || howMany > warehouses[which].fetchProductAmount(warehouses[which].findProductByID(ID)))
                        howMuch = palletTrucks[i].fetchMaximumLoad() + 1;
                }while(howMuch > palletTrucks[i].fetchMaximumLoad() &&
                       ( std::cerr << "Podaj odpowiednia wartosc( niemniejsza od 0 i mniejsza od maksymalnego udzwigu)!" << '\n', 1) );
                warehouses[which].sendProduct(&palletTrucks[i], ID, howMany);
                std::cout << "Udalo sie zaladowac towar.\n";
                break;
            case 4:
                if(warehouses.empty() ){
                    std::cerr << "Najpierw stworz magazyn!\n";
                    break;
                }
                which = chooseWarehouse(warehouses);
                std::cout << "Ktory paleciak rozladowac?\n";
                printPalletTrucks(palletTrucks);
                std::cout << "Podaj ID: ";
                i = readInt();
                std::cout << "\nWybierz produkt.\n";
                palletTrucks[i].printPaleciak();
                std::cout << "Podaj ID: ";
                ID = readInt();
                std::cout << "\nIle chcesz rozladowac?\n";
                do {
                    howMany = readInt();
                    if( howMany < 0 || howMany > palletTrucks[i].fetchProductAmount(palletTrucks[i].findProductByID(ID))) howMany = palletTrucks[i].fetchMaximumLoad() + 1;
                }while(howMany > palletTrucks[i].fetchProductAmount(palletTrucks[i].findProductByID(ID)) &&
                       ( std::cerr << "Podaj odpowiednia wartosc( wieksza od 0 i nie wieksza od maksymalnego ciezaru produktu)!" << '\n', 1) );
                warehouses[which].collect(&palletTrucks[i], ID, howMany);
                break;
            default :
                std::cerr << "Podaj poprawna wartosc(0-4)" << '\n';
                break;
        }
    }while(choice != 0);
}

void printPalletTrucks(std::vector<PalletTruck>& palletTrucks){
    if( palletTrucks.empty())
        std::cerr << "Nie stowrzyles jeszcze zadnego paleciaka.\n";
    for(int i = 0; i < palletTrucks.size(); ++i) {
        palletTrucks[i].printPaleciak();
    }
}

void printWarehouses(std::vector<Warehouse>& warehouses){
    if( warehouses.empty())
        std::cerr << "Nie stowrzyles jeszcze zadnego magazynu.\n";

    for (auto& item : warehouses){
        item.printWarehouse();
    }
}

int findWarehouse(std::vector<Warehouse>& warehouses, int ID) {
    for (int i = 0; i < warehouses.size(); ++i) {
        if (warehouses[i].fetchID() == ID)
            return i;
    }
    return -1;
}

void receive(Warehouse& warehouse ) {
    std::cout << "Oto lista towarow:" << '\n';
    warehouse.printWarehouse();

    std::cout << "Ktory towar chcesz zmienic(podaj ID)?" << '\n';
    int i = readInt();
    int index = warehouse.findProductByID(i);

    if ( index == -1 ) {
        std::cerr << "Nie udalo sie znalezc elementu z takim ID." << '\n';
        return;
    }

    int j;
    do {
        std::cout << "Ile towarow chcesz dodac?" << '\n';
        j = readInt();
    } while ( ( j < 0 ) && ( std::cerr << "Podaj odpowiednia ilosc!" << '\n', 1) );

    warehouse.changeProduct(index, j, Warehouse::manipulateProducts::decrease);
}

void dispense(Warehouse& warehouse ) {
    std::cout << "Oto lista towarow: " << '\n';
    warehouse.printWarehouse();

    std::cout << "Ktory towar chcesz zmienic(podaj ID)?" << '\n';
    int i = readInt();
    int index = warehouse.findProductByID(i);
    if ( index == -1 ) {
        std::cerr << "Nie udalo sie znalezc elementu z takim ID." << '\n';
        return;
    }

    int j;
    if(warehouse.fetchProductAmount(i) > 0) {

        do {
            std::cout << "Ile towarow chcesz odjac?" << '\n';
            j = readInt();
            if (j < 0){
                j = warehouse.fetchProductAmount(i) + 1;    // ustawiam ilosc na wieksza od towaru, zeby zgadzal sie warunek petli,
                // wypisal sie blad i uzytkownik podal odpowiednia - nieujemna wartosc
            }
        }while((j > warehouse.fetchProductAmount(i) ) && ( std::cerr << "Podaj odpowiednia ilosc!" << '\n', 1) );
        // wypisuje blad dopiero za druga iteracja petli,
        warehouse.changeProduct(index, j, Warehouse::manipulateProducts::increase);
    }
    else
        std::cout << "Ilosc towarow to 0. Nie mozna nic odjac." << '\n';
}

int chooseWarehouse(std::vector<Warehouse> &warehouses) {
    unsigned int which = 0;
    int check = 0;
    std::cout << "Na ktorym magazynie chcesz pracowac?" << '\n';
    printWarehouses(warehouses);
    do {
        check = 0;
        std::cout << "Podaj ID: ";
        which = readInt();
        std::cout << '\n';
        for (auto & warehouse : warehouses){
            if( which == warehouse.fetchWarehouseID() )
                check = 1;
        }
        if( check == 0 ) which = warehouses.size() + 1;

    }while(which > warehouses.size() && ( std::cerr << "Podaj odpowiednia wartosc!" << '\n', 1) );
    return which;
}
