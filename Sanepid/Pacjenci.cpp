#include "Pacjenci.h"


void Pacjenci::dodajPacjenta()
{
	Pacjent pacnejt;
	pacnejt.wczytajDane();
	lista.dodajNaPoczatek(pacnejt);
}

void Pacjenci::wypiszPacjentow()
{
	wypiszPacjentow(lista);
}

void Pacjenci::wypiszWedlugDlugosciKwarantanny()
{
	Lista<Pacjent> listaSort = lista;
	listaSort.sortuj(Pacjent::mniejszy);
	wypiszPacjentow(listaSort);
}

void Pacjenci::wyszukajPoTekscie()
{
	std::string text;
	std::string enter;
	std::getline(std::cin, enter);
	std::cout << "podaj tekst wyszukiwania:";
	std::getline(std::cin, text);

	WypiszNaglowekTabeli();

	Wskaznik<Pacjent> wsk = lista.WskaznikNaPoczatek();
	int numery = 1;
	for (Wskaznik<Pacjent> wsk = lista.WskaznikNaPoczatek(); wsk != lista.WskaznikNaKoniec(); wsk++)
	{
		if ((*wsk).zawieraText(text))
		{
			(*wsk).wypiszDaneDoTabeli(numery);
		}
		numery++;
	}

	wypiszLinie();
}

void Pacjenci::wyszukajPoDacie()
{
	Data data;
	std::cout << "podaj dzien:";
	std::cin >> data.dzien;
	std::cout << "podaj miesiac:";
	std::cin >> data.miesiac;
	std::cout << "podaj rok:";
	std::cin >> data.rok;

	WypiszNaglowekTabeli();

	Wskaznik<Pacjent> wsk = lista.WskaznikNaPoczatek();
	int numery = 1;
	for (Wskaznik<Pacjent> wsk = lista.WskaznikNaPoczatek(); wsk != lista.WskaznikNaKoniec(); wsk++)
	{
		if ((*wsk).zawieraDate(data))
		{
			(*wsk).wypiszDaneDoTabeli(numery);
		}
		numery++;
	}

	wypiszLinie();
}

void Pacjenci::usunPacjenta()
{
	std::cout << "podaj numer pacjenta ktorego chcesz usunac (wg listy z kolejnoscia dodania!): ";
	int numer;
	std::cin >> numer;
	if (lista.usunElement(numer - 1))
	{
		std::cout << "usunieto pacjenta" << std::endl;
	}
	else
	{
		std::cout << "nie znaleziono pacjenta o podanym numerze" << std::endl;
	}
}

void Pacjenci::zapisz()
{
	lista.zapisz("pacjenci.txt", Pacjent::zapisz);
}

void Pacjenci::wczytaj()
{
	lista.wczytaj("pacjenci.txt", Pacjent::wczytaj);
}

void Pacjenci::wypiszPacjentow(Lista<Pacjent>& lista)
{
	WypiszNaglowekTabeli();

	Wskaznik<Pacjent> wsk = lista.WskaznikNaPoczatek();
	int numery = 1;
	for (Wskaznik<Pacjent> wsk = lista.WskaznikNaPoczatek(); wsk != lista.WskaznikNaKoniec(); wsk++)
	{
		(*wsk).wypiszDaneDoTabeli(numery++);
	}

	wypiszLinie();
}

void Pacjenci::WypiszNaglowekTabeli()
{
	wypiszLinie();
	std::cout << "|  LP | imie       | nazwisko   | adres                     | ost. dzien kw. |" << std::endl;
	wypiszLinie();
}

void Pacjenci::wypiszLinie()
{
	std::cout << "+-----+------------+------------+---------------------------+----------------+" << std::endl;
}