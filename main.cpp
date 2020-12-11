#include "Magazyn.h"
#include "TowarCiekly.h"
#include "Towar.h"
#include "TowarSypki.h"



void menuMagazyn(std::vector<Magazyn*>& magazyny);
void menuProdukt(std::vector<Magazyn*>& magazyny);
void wypiszMagazyny(std::vector<Magazyn*>& magazyny);
int findWarehouse(std::vector<Magazyn*>& magazyny,int ID);
std::string readString();
int readInt();

int main() {
    std::vector<Magazyn*> magazyny;
    std::vector<Paleciak*> paleciaki;
    int choice = 0;

    do {
        std::cout <<"\n---====== MENU =====---\n"
                    "0: Wychodzi z programu.\n"
                    "1: Zarzadzaj magazynami.\n"
                    "2: Zarzadzaj produktami w magazynie.\n"
                    "3: Wypisz wszystkie magazyny.\n"
                    "Wybierz akcje:" << '\n';
        choice = readInt();
        switch (choice) {
            case 0:
                std::cout << "Koniec programu." << '\n';
                break;
            case 1:
                menuMagazyn(magazyny);
                break;
            case 2:
                menuProdukt(magazyny);
                break;
            case 3:
                wypiszMagazyny(magazyny);
                break;
            default:
                std::cerr << "Podaj poprawna ilosc!" << '\n';
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

void menuProdukt(std::vector<Magazyn*>& magazyny){
    int choice = 0;
    int which = 0;

    do {
        std::cout << "Na ktorym magazynie chcesz pracowac?" << '\n';
        which = readInt();
        if( which < 0) which = magazyny.size() + 1;

    }while(which < magazyny.size() && ( std::cerr << "Podaj odpowiednia ilosc!" << '\n', 1) );

    do {
        std::cout <<"\n---====== MENU =====---\n"

                    "0: Wychodzi z menu zarzadzania produktami.\n"
                    "1: Dodaj produkt.\n"
                    "2: Wypisz produkty.\n"//podaj ID ktorego chcesz wypisac
                    "3: Zmien magazyn.\n"
                    "Wybierz akcje:" << '\n';
        choice = readInt();
        switch (choice) {
            case 0:
                std::cout << "Wracam do menu.\n";
                break;
            case 1:
                std::cout <<"Jaki typ prduktu chcesz stworzyc?\n"
                            "0: Towar.\n"
                            "1: Towar Sypki.\n"
                            "2: Towar Ciekly.\n"
                            "Wybierz akcje:" << '\n';
                int whichProduct = readInt();
                switch (whichProduct) {
                    case 0:
                        Towar* towar;
                        magazyny[which].addProduct();
                        break;
                    case 1:
                        TowarSypki* towar;
                        magazyny[which].addProduct();
                        break;
                    case 2:
                        TowarCiekly* towar;
                        magazyny[which].addProduct();
                        break;
                }

                break;
            case 2:
                break;
            case 3:
                do {
                    std::cout << "Na ktorym magazynie chcesz pracowac?" << '\n';
                    which = readInt();
                    if( which < 0) which = magazyny.size() + 1;

                }while(which < magazyny.size() && ( std::cerr << "Podaj odpowiednia ilosc!" << '\n', 1) );
                break;
//          default :
//              std::cout << "Podaj poprawna wartosc!" << '\n';
        }
    }while(choice != 0);
}

void menuMagazyn(std::vector<Magazyn*>& magazyny){
    int choice = 0;
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
//                Magazyn* temp = new Magazyn();
//                magazyny.emplace_back(temp);
                break;
            case 2:
                std::cout << "Ktory magazyn chcesz wypisac?(Podaj ID)\n";
                int i = readInt();
                int index = findWarehouse(magazyny,i);
                if (index == -1)
                    std::cout << "Nie udalo sie znalezc magazynu z takim ID.\n";
                else
                    magazyny[index]->printWarehouse();
                break;
//            default :
//                std::cout << "Podaj poprawna wartosc!" << '\n';
        }
    }while(choice != 0);

}

void wypiszMagazyny(std::vector<Magazyn*>& magazyny){
    for (auto& item : magazyny){
        item->printWarehouse();
    }
}

int findWarehouse( std::vector<Magazyn*>& magazyny, int ID) {
    for (int i = 0; i < magazyny.size(); ++i) {
        if (magazyny[i]->fetchID() == ID)
            return i;
    }
    return -1;
}