#include "helperFun.h"

void menuProduct(std::vector<Warehouse*>& warehouses){
    int choice;
    if(warehouses.empty() ){
        std::cerr << "Najpierw stworz magazyn!\n";
        return;
    }
    int which = chooseWarehouse(warehouses);
    std::string name;
    do {
        std::cout <<"\n---===== MENU ZARZADANIA PRODUKTAMI =====---\n"
                    "0: Wychodzi z menu zarzadzania produktami.\n"
                    "1: Stworz produkt.\n"
                    "2: Zmien ilosc produktu.\n"
                    "3: Wypisz produkty w magazynie.\n"
                    "4: Zmien magazyn.\n"
                    "Wybierz akcje(0-4):";
        choice = readInt();
        std::cout <<'\n';
        switch ( choice ) {
            case 0:
                std::cout << "\nWracam do menu.\n";
                break;
            case 1:
                std::cout <<"\n---===== TWORZENIE PRODUKTU =====---\n"
                            "Jaki typ prduktu chcesz stworzyc?\n"
                            "0: Towar.\n"
                            "1: Towar Sypki.\n"
                            "2: Towar Ciekly.\n"
                            "Wybierz akcje(0-2):";
                switch ( readInt() ) {
                    case 0:
                        std::cout << "Podaj nazwe produktu.\n";
                        name = readString();
                        std::cout << "Podaj wage pojedynczego produktu w kg.\n";
                        warehouses[which]->addProduct(new UnitProduct(warehouses[which]->fetchProductID(), name, readDouble()));
                        break;
                    case 1:
                        std::cout << "Podaj nazwe produktu.\n";
                        warehouses[which]->addProduct(new LooseProduct(warehouses[which]->fetchProductID(), readString(), 1));
                        break;
                    case 2:
                        std::cout << "Podaj nazwe produktu.\n";
                        name = readString();
                        std::cout << "Podaj wage jednego litra produktu w kg.\n";
                        warehouses[which]->addProduct(new LiquidProduct(warehouses[which]->fetchProductID(), name, readDouble() ));
                        break;
                    default :
                        std::cerr << "Podaj poprawna wartosc(0-2)!" << '\n';
                }
                break;
            case 2:
                std::cout <<"\n---===== ZARZADZANIE TOWAREM =====---\n"
                            "Co chcesz zrobic z towarami?\n"
                            "0: Wroc do poprzedniego menu.\n"
                            "1: Dodaj towar.\n"
                            "2: Odejmij towar.\n"
                            "3: Wypisz magazyn.\n"
                            "Wybierz akcje(0-3):";

                switch ( readInt() ) {
                    case 0:
                        std::cout << "\nWracam do poprzedniego menu.\n";
                        break;
                    case 1:
                        if (warehouses[which]->fetchProductCount() > 0)
                            receive(*warehouses[which]);
                        else
                            std::cerr << "\nNajpierw dodaj towar!" << '\n';
                        break;

                    case 2:
                        if (warehouses[which]->fetchProductCount() > 0)
                            dispense(*warehouses[which]);
                        else
                            std::cerr << "Najpierw dodaj towar!" << '\n';
                        break;
                    case 3:
                        warehouses[which]->printWarehouse();
                        break;
                    default :
                        std::cerr << "Podaj poprawna wartosc()!" << '\n';
                }
            case 3:
                warehouses[which]->printWarehouse();
                break;
            case 4:
                which = chooseWarehouse(warehouses);
                break;
            default :
                std::cerr << "Podaj poprawna wartosc(0-4)!" << '\n';
        }
    }while(choice != 0);

}

void menuWarehouse(std::vector<Warehouse*>& warehouses){
    int choice;
    static int warehouseID = 0;
    int i;
    int index;
    do {
        std::cout <<"\n---===== MENU ZARZADZANIA MAGAZYNAMI =====---\n"
                    "0: Wychodzi z menu zarzadzania magazynami.\n"
                    "1: Utworz magazyn.\n"
                    "2: Zarzadzaj produktami w magazynie.\n"
                    "3: Wypisz magazyn.\n"
                    "Wybierz akcje:";
        choice = readInt();
        switch (choice) {
            case 0:
                std::cout << "\nWracam do glownego menu.\n";
                break;
            case 1:
                std::cout << "Tworze magazyn.\n";
                warehouses.push_back( new Warehouse(warehouseID++) );
                break;
            case 2:
                menuProduct(warehouses);
                break;
            case 3:
                if(warehouses.empty() ){
                    std::cerr << "Najpierw stworz magazyn!\n";
                    break;
                }
                std::cout << "Ktory magazyn chcesz wypisac?\n" << "Dostepne ID:" << '\t';
                for (auto & warehouse : warehouses){
                    std::cout << warehouse->fetchID() << "  ";
                }
                std::cout << "Podaj ID: ";
                i = readInt();
                std::cout << '\n';
                index = findWarehouse(warehouses, i);
                if (index == -1)
                    std::cerr << "Nie udalo sie znalezc magazynu z takim ID.\n";
                else
                    warehouses[index]->printWarehouse();
                break;
            default :
                std::cerr << "Podaj poprawna wartosc(0-2)!" << '\n';
        }
    }while(choice != 0);
}

void menuPalletTruck(std::vector<Warehouse*>& warehouses, std::vector<PalletTruck*>& palletTrucks){
    int choice;
    int i;
    int ID;
    int which;
    int howMany;
    double howMuch;
    do {
        std::cout << "\n---===== MENU ZARZADZANIA PALECIAKAMI =====---\n"
                     "0: Wychodzi z menu zarzadzania paleciakami.\n"
                     "1: Utworz paleciak.\n"
                     "2: Zaladuj paleciak.\n"
                     "3: Rozladuj paleciak.\n"
                     "4: Wypisz paleciaki.\n"
                     "Wybierz akcje:";
        choice = readInt();
        switch (choice) {
            case 0:
                std::cout << "\nWracam do glownego menu.\n";
                break;
            case 1:
                do {
                    std::cout << "\nPodaj maksymalny udzwig w kg.\n";
                    howMuch = readDouble();
                }while(howMuch <= 0 && ( std::cerr << "Podaj odpowiednia wartosc(wieksza od 0)!" << '\n', 1) );
                palletTrucks.push_back( new PalletTruck(howMuch) );
                break;
            case 2:
                if(warehouses.empty() ){
                    std::cerr << "Najpierw stworz magazyn!\n";
                    break;
                }
                which = chooseWarehouse(warehouses);
                if( warehouses[which]->isEmpty() ) {
                    std::cerr << "Magazyn jest pusty, najpierw dodaj tam produkty.\n";
                    break;
                }
                std::cout << "Ktory paleciak zaladowac?\n";
                i = choosePalletTruck(palletTrucks);
                std::cout << "\nWybierz produkt.\n";
                warehouses[which]->printWarehouse();
                std::cout << "Podaj ID: ";
                ID = readInt();
                std::cout << '\n';

                do {
                    std::cout << "Ile chcesz zaladowac?\n" << "Dostepna ilosc produktu: " << warehouses[which]->fetchProductAmount(warehouses[which]->findProductByID(ID))
                              << " Kazdy produkt wazy " << warehouses[which]->fetchProductWeight(warehouses[which]->findProductByID(ID)) << "kg" << '\n';
                    std::cout << "Podaj w sztukach: ";
                    howMany = readInt();
                    howMuch = howMany *  warehouses[which]->fetchProductWeight(warehouses[which]->findProductByID(ID));
                    std::cout << "\nProbuje zaladowac " << howMuch << "kg produktu." << '\n';

                    if( howMany < 0 || palletTrucks[i]->fetchMaximumLoad()  < howMuch  || howMany > warehouses[which]->fetchProductAmount(warehouses[which]->findProductByID(ID)))
                        howMuch = palletTrucks[i]->fetchMaximumLoad() + 1;
                }while(howMuch + palletTrucks[i]->fetchCurrentLoad() > palletTrucks[i]->fetchMaximumLoad() &&
                       ( std::cerr << "Podaj odpowiednia wartosc( niemniejsza od 0 i taka aby po zaladowaniu nie nie przekraczala maksymalnego udzwigu)!" << '\n', 1) );
                warehouses[which]->sendProduct(palletTrucks[i], ID, howMany);
                std::cout << "Udalo sie zaladowac towar.\n";
                break;
            case 3:
                if(warehouses.empty() ){
                    std::cerr << "Najpierw stworz magazyn!\n";
                    break;
                }
                which = chooseWarehouse(warehouses);
                std::cout << "Ktory paleciak rozladowac?\n";
                i = choosePalletTruck(palletTrucks);
                std::cout << "\nWybierz produkt.\n";
                palletTrucks[i]->printPaleciak();
                std::cout << "Podaj ID: ";
                ID = readInt();
                std::cout << "\nIle chcesz rozladowac?\n";
                do {
                    howMany = readInt();
                    if( howMany < 0 || howMany > palletTrucks[i]->fetchProductAmount(palletTrucks[i]->findProductByID(ID))) howMany = static_cast<int>(palletTrucks[i]->fetchMaximumLoad()) + 10;
                }while(howMany > palletTrucks[i]->fetchProductAmount(palletTrucks[i]->findProductByID(ID)) &&
                       ( std::cerr << "Podaj odpowiednia wartosc( wieksza od 0 i nie wieksza od maksymalnego ciezaru produktu)!" << '\n', 1) );
                warehouses[which]->collect(palletTrucks[i], ID, howMany);
                break;
            case 4:
                printPalletTrucks(palletTrucks);
                break;
            default :
                std::cerr << "Podaj poprawna wartosc(0-4)" << '\n';
                break;
        }
    }while(choice != 0);
}

void printPalletTrucks(std::vector<PalletTruck*>& palletTrucks){
    if( palletTrucks.empty())
        std::cerr << "Nie stowrzyles jeszcze zadnego paleciaka.\n";
    for(auto & palletTruck : palletTrucks) {
        palletTruck->printPaleciak();
    }
}

void printWarehouses(std::vector<Warehouse*>& warehouses){
    if( warehouses.empty())
        std::cerr << "Nie stowrzyles jeszcze zadnego magazynu.\n";

    for (auto& item : warehouses){
        item->printWarehouse();
    }
}

int findWarehouse(std::vector<Warehouse*>& warehouses, int ID) {
    for (int i = 0; i < warehouses.size(); ++i) {
        if (warehouses[i]->fetchID() == ID)
            return i;
    }
    return -1;
}

void receive(Warehouse& warehouse ) {
    std::cout << "\nOto lista towarow:" << '\n';
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

    std::cout << "Ktory towar chcesz zmienic?" << '\n';
    std::cout << "Podaj ID: ";
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

int chooseWarehouse(std::vector<Warehouse*>& warehouses) {
    int which;
    int check;
    std::cout << "\nNa ktorym magazynie chcesz pracowac?" << '\n';
    printWarehouses(warehouses);
    do {
        check = 0;
        std::cout << "Podaj ID: ";
        which = readInt();
        std::cout << '\n';
        for (auto & warehouse : warehouses){
            if( which == warehouse->fetchWarehouseID() )
                check = 1;
        }
        if( check == 0 ) which = static_cast<int>(warehouses.size()) + 1;

    }while(which > warehouses.size() && ( std::cerr << "Podaj odpowiednia wartosc!" << '\n', 1) );
    return which;
}

int choosePalletTruck(std::vector<PalletTruck*>& palletTrucks) {
    int which;
    int check;
    printPalletTrucks(palletTrucks);
    do {
        check = 0;
        std::cout << "Podaj ID: ";
        which = readInt();
        std::cout << '\n';
        for (auto & warehouse : palletTrucks){
            if( which == warehouse->fetchPalletID() )
                check = 1;
        }
        if( check == 0 ) which = static_cast<int>(palletTrucks.size()) + 1;

    }while(which > palletTrucks.size() && ( std::cerr << "Podaj odpowiednia wartosc!" << '\n', 1) );
    return which;
}
