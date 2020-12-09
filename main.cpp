#include "Magazyn.h"


void menuMagazyn(std::vector<Magazyn*> magazyny);
void menuProdukt(std::vector<Magazyn*> magazyny);
void wypiszMagazyny(std::vector<Magazyn*> magazyny);
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
                    "2: Zarzadzaj produktami.\n"
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
                //menuProdukt();
                break;
            case 3:
                //wypiszMagazyny();
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

void menuMagazyn(std::vector<Magazyn*> magazyny){
    int choice = 0;
    do {
        std::cout <<"\n---====== MENU =====---\n"
                    "0: Wychodzi z menu zarzadzania magazynem.\n"
                    "1: Utworz magazyn.\n"
                    "2: Usun magazyn.\n"
                    "2: Wypisz magazyn.\n"//podaj ID ktorego chcesz wypisac
                    "Wybierz akcje:" << '\n';
        choice = readInt();
        switch (choice) {
            case 0:
                std::cout << "Wracam do menu.\n";
                break;
            case 1:
                std::cout << "Tworze magazyn.\n";
//                Magazyn* temp = new Magazyn(magazyny.size()+1);
//                magazyny.emplace_back(*temp);
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
//            default:
//                std::cout << "Podaj poprawna wartosc!" << '\n';
        }
    }while(choice != 0);
}

void menuProdukt(){
    int choice = 0;
    do {

    }while(choice != 0);

}

void wypiszMagazyny(std::vector<Magazyn*> magazyny){

}

int findWarehouse( std::vector<Magazyn*>& magazyny, int ID) {
    for (int i = 0; i < magazyny.size(); ++i) {
        if (magazyny[i]->fetchID() == ID)
            return i;
    }
    return -1;
}