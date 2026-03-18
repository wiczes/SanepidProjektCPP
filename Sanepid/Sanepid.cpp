#include <iostream>
#include "Pacjenci.h"


int main()
{
    int wybor = 0;
    Pacjenci pacjenci;
    pacjenci.wczytaj();
    while (wybor != 7)
    {
        std::cout << "MENU:" << std::endl;
        std::cout << "1 - wypisz pacjentow wedlug kolejnosci dodawania" << std::endl;
        std::cout << "2 - wypisz pacjentow wedlug dlugosci przebywania na kwarantannie" << std::endl;
        std::cout << "3 - dodaj pacjenta" << std::endl;
        std::cout << "4 - usun pacjenta" << std::endl;
        std::cout << "5 - wyszukaj pacjenta po tekscie" << std::endl;
        std::cout << "6 - wyszukaj pacjenta po dacie" << std::endl;
        std::cout << "7 - wyjscie" << std::endl;
        std::cout << "wybierz opcje:";
        std::cin >> wybor;

        switch (wybor)
        {
        case 1:
            pacjenci.wypiszPacjentow();
            break;
        case 2:
            pacjenci.wypiszWedlugDlugosciKwarantanny();
            break;
        case 3:
            pacjenci.dodajPacjenta();
            break;
        case 4:
            pacjenci.usunPacjenta();
            break;
        case 5:
            pacjenci.wyszukajPoTekscie();
            break;
        case 6:
            pacjenci.wyszukajPoDacie();
            break;
        }
    }
    pacjenci.zapisz();
}
