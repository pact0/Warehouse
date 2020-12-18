#include "Magazyn.h"
#include "TowarCiekly.h"
#include "Towar.h"
#include "TowarSypki.h"



void menuMagazyn(std::vector<Magazyn>& warehouses);
void menuProdukt(std::vector<Magazyn>& warehouses);
void menuPaleciak(std::vector<Magazyn>& warehouses, std::vector<Paleciak>& paleciaki);
void printWarehouses(std::vector<Magazyn>& warehouses);
int chooseWarehouse(std::vector<Magazyn>& warehouses);
void printPaleciaki(std::vector<Paleciak>& paleciaki);
int findWarehouse(std::vector<Magazyn>& warehouses, int ID);
void przyjecie(Magazyn& warehouse);
void odbior(Magazyn& warehouse);

std::string readString();
int readInt();

int main() {
    std::vector<Magazyn> warehouses;
    std::vector<Paleciak> paleciaki;
    int choice = 0;

    do {
        std::cout <<"\n---====== MENU =====---\n"
                    "0: Wychodzi z programu.\n"
                    "1: Zarzadzaj magazynami.\n"
                    "2: Zarzadzaj produktami w magazynie.\n"
                    "3: Zarzadzaj paleciakami.\n"
                    "4: Wypisz wszystkie warehouses.\n"
                    "Wybierz akcje(0-4):" << '\n';
        choice = readInt();
        switch (choice) {
            case 0:
                std::cout << "Koniec programu." << '\n';
                break;
            case 1:
                menuMagazyn(warehouses);
                break;
            case 2:
                menuProdukt(warehouses);
                break;
            case 3:
                menuPaleciak(warehouses, paleciaki);
                break;
            case 4:
                printWarehouses(warehouses);
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

std::string readString() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

void menuProdukt(std::vector<Magazyn>& warehouses){
    int choice = 0;
    int which = chooseWarehouse(warehouses);
    int whichProduct;
    int productChoice;

    do {
        std::cout <<"\n---====== MENU =====---\n"
                    "0: Wychodzi z menu zarzadzania produktami.\n"
                    "1: Dodaj produkt.\n"
                    "2: Zmien produkt.\n"
                    "3: Wypisz produkty.\n"//podaj ID ktorego chcesz wypisac
                    "4: Zmien magazyn.\n"
                    "Wybierz akcje(0-4):" << '\n';
        choice = readInt();
        switch ( choice ) {
            case 0:
                std::cout << "Wracam do menu.\n";
                break;
            case 1:
                std::cout <<"Jaki typ prduktu chcesz stworzyc?\n"
                            "0: Towar.\n"
                            "1: Towar Sypki.\n"
                            "2: Towar Ciekly.\n"
                            "Wybierz akcje(0-2):" << '\n';
                std::cout << "Podaj nazwe produktu.\n";
                switch ( readInt() ) {
                    case 0:
                        warehouses[which].addProduct(new Towar(warehouses[which].fetchProductID(), readString() ));
                        break;
                    case 1:
                        warehouses[which].addProduct(new TowarSypki(warehouses[which].fetchProductID(), readString()));
                        break;
                    case 2:
                        warehouses[which].addProduct(new TowarCiekly(warehouses[which].fetchProductID(), readString() ));
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
                            "Wybierz akcje(0-3):\n";

                switch ( readInt() ) {
                    case 0:
                        break;
                    case 1:
                        if (warehouses[which].fetchProductCount() > 0)
                            przyjecie(warehouses[which]);
                        else
                            std::cerr << "Najpierw dodaj towar!" << '\n';
                        break;

                    case 2:
                        if (warehouses[which].fetchProductCount() > 0)
                            odbior(warehouses[which]);
                        else
                            std::cerr << "Najpierw dodaj towar!" << '\n';
                        break;
                    case 3:
                        warehouses[which].printWarehouse();
                        break;
                    default :
                        std::cerr << "Podaj poprawna wartosc()!" << '\n';
                        break;
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

void menuMagazyn(std::vector<Magazyn>& warehouses){
    int choice = 0;
    static int warehouseID = 0;
    int i;
    int index;
    do {
        std::cout <<"\n---====== MENU =====---\n"
                    "0: Wychodzi z menu zarzadzania magazynami.\n"
                    "1: Utworz magazyn.\n"
                    "2: Wypisz magazyn.\n"//podaj ID ktorego chcesz wypisac
                    "Wybierz akcje:" << '\n';
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
                std::cout << "Ktory magazyn chcesz wypisac?(Podaj ID)\n" << "Dostepne ID:" << '\t';
                for (int j = 0; j < warehouses.size(); j++){
                    std::cout << warehouses[j].fetchID() << "  ";
                }
                std::cout << '\n';
                i = readInt();
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

void menuPaleciak(std::vector<Magazyn>& warehouses, std::vector<Paleciak>& paleciaki){
    int choice = 0;
    int i = 0;
    int ID;
    int which = chooseWarehouse(warehouses);
    int howMuch;
    do {
        std::cout << "\n---====== MENU =====---\n"
                     "0: Wychodzi z menu zarzadzania paleciakami.\n"
                     "1: Utworz paleciak.\n"
                     "2: Wypisz paleciaki.\n"//podaj ID ktorego chcesz wypisac
                     "3: Zaladuj paleciak.\n"
                     "4: Rozladuj paleciak.\n"
                     "5: Zmien magazyn.\n"
                     "Wybierz akcje:" << '\n';
        choice = readInt();
        switch (choice) {
            case 0:
                std::cout << "Wychodze z menu.\n";
                break;
            case 1:
                std::cout << "Podaj maksymalny udzwig w kg.\n";
                paleciaki.emplace_back(readInt());
                break;
            case 2:
                printPaleciaki(paleciaki);
                break;
            case 3:
                std::cout << "Ktory paleciak zaladowac.\n";
                i = readInt();
                std::cout << "Wybierz produkt(podaj ID).\n";
                warehouses[which].printWarehouse();
                ID = readInt();

                std::cout << "Ile chcesz zaladowac?\n";
                do {
                    howMuch = readInt();
                    if( howMuch < 0) howMuch = paleciaki[i].fetchMaximumLoad() + 1;
                }while(howMuch > paleciaki[i].fetchMaximumLoad() && ( std::cerr << "Podaj odpowiednia wartosc( wieksza od 0 i mniejsza od maksymalnego udzwigu)!" << '\n', 1) );
                // check whether howMuch is
                warehouses[which].wydaj(&paleciaki[i], ID, howMuch);
                break;
            case 4:
                std::cout << "Ktory paleciak rozladowac.\n";
                i = readInt();
                std::cout << "Wybierz produkt(podaj ID).\n";
                warehouses[which].printWarehouse();
                ID = readInt();
                std::cout << "Ile chcesz rozladowac?\n";
                do {
                    howMuch = readInt();
                    if( howMuch < 0) howMuch = paleciaki[i].fetchMaximumLoad() + 1;
                }while(howMuch > paleciaki[i].fetchProductAmount(paleciaki[i].findProductByID(ID)) && ( std::cerr << "Podaj odpowiednia wartosc( wieksza od 0 i nie wieksza od maksymalnego ciezaru produktu)!" << '\n', 1) );
                warehouses[which].przyjmij(&paleciaki[i], ID, readInt());
                break;
            case 5:
                which=chooseWarehouse(warehouses);
                break;
            default :
                std::cerr << "Podaj poprawna wartosc(0-5)" << '\n';
                break;
        }
    }while(choice != 0);
}

void printPaleciaki(std::vector<Paleciak>& paleciaki){
    for (int i = 0; i < paleciaki.size(); ++i) {
        paleciaki[i].printPaleciak();
    }
}

void printWarehouses(std::vector<Magazyn>& warehouses){
    for (auto& item : warehouses){
        item.printWarehouse();
    }
}

int findWarehouse(std::vector<Magazyn>& warehouses, int ID) {
    for (int i = 0; i < warehouses.size(); ++i) {
        if (warehouses[i].fetchID() == ID)
            return i;
    }
    return -1;
}

void przyjecie( Magazyn& warehouse ) {
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

    warehouse.changeProduct(index, j, Magazyn::manipulateProducts::zwieksz);
}

void odbior( Magazyn& warehouse ) {
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
        // ( std::cerr << "Odejmujesz za duzo towarow!" << '\n', 1) zwraca zawsze druga wartosc czyli 1 ( nie bylem pewny co zwraca cerr )
        warehouse.changeProduct(index, j, Magazyn::manipulateProducts::zmniejsz);
    }
    else
        std::cout << "Ilosc towarow to 0. Nie mozna nic odjac." << '\n';
}

int chooseWarehouse(std::vector<Magazyn> &warehouses) {
    int which = 0;
    std::cout << "Na ktorym magazynie chcesz pracowac?(Podaj ID)" << '\n';
    printWarehouses(warehouses);
    do {
        which = readInt();
        if( which < 0) which = warehouses.size() + 1;
    }while(which > warehouses.size() && ( std::cerr << "Podaj odpowiednia wartosc!" << '\n', 1) );
    return which;
}
