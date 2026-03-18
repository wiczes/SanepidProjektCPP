#pragma once
#include "Wskaznik.h"
#include <string>
#include <fstream>


template<typename T>
struct Element
{
	Element* nast;
	T dane;
};

template<typename T>
class Lista
{
private:
	Element<T>* poczatek;
	Element<T>* koniec;

public:
	Lista()
	{
		poczatek = nullptr;
		koniec = nullptr;
	}
	Lista(const Lista<T>& lista)
	{
		skopiuj(lista, this);
	}

	Lista<T>& operator=(const Lista<T>& lista)
	{
		if (this != &lista) {
			wyczysc();
			skopiuj(lista, this);
		}
		return *this;
	}

	~Lista()
	{
		wyczysc();
	}

	void wyczysc()
	{
		Element<T>* usuwany;
		while (poczatek != nullptr)
		{
			usuwany = poczatek;
			poczatek = poczatek->nast;
			delete usuwany;
		}
		poczatek = nullptr;
		koniec = nullptr;
	}

	void dodajNaPoczatek(const T& dane)
	{
		Element<T>* nowy = new Element<T>;
		nowy->dane = dane;

		if (poczatek == nullptr)
		{
			koniec = nowy;
		}

		nowy->nast = poczatek;
		poczatek = nowy;
	}

	void dodajNaKoniec(const T& dane)
	{
		Element<T>* nowy = new Element<T>;
		nowy->dane = dane;
		nowy->nast = nullptr;
		if (koniec == nullptr)
		{
			poczatek = nowy;
			koniec = nowy;
		}
		else
		{
			koniec->nast = nowy;
			koniec = nowy;
		}
	}

	Wskaznik<T> WskaznikNaPoczatek()
	{
		Wskaznik<T> wskaznik;
		wskaznik.poprzedni = nullptr;
		wskaznik.wskazywany = poczatek;
		return wskaznik;
	}

	Wskaznik<T> WskaznikNaKoniec()
	{
		Wskaznik<T> wskaznik;
		wskaznik.poprzedni = koniec;
		wskaznik.wskazywany = nullptr;
		return wskaznik;
	}

	void sortuj(bool (*mniejszy)(T&, T&))
	{
		Element<T>* pom = poczatek;
		poczatek = nullptr;
		koniec = nullptr;
		while (pom != nullptr)
		{
			Element<T>* wstawiany = pom;
			pom = pom->nast;
			dodajNaOpowiedniaPozycje(poczatek, koniec, wstawiany, mniejszy);
		}
	}

	bool usunElement(int index)
	{
		if (index < 0 || poczatek == nullptr)
		{
			return false;
		}

		if (index == 0)
		{
			Element<T>* usuwany = poczatek;
			poczatek = poczatek->nast;
			if (poczatek == nullptr)
			{
				koniec = nullptr;
			}
			delete usuwany;
			return true;
		}

		Element<T>* pom = poczatek;

		for (int i = 0; pom->nast != nullptr && i < index - 1; i++)
		{
			pom = pom->nast;
		}

		if (pom->nast == nullptr)
		{
			return false;
		}
		Element<T>* usuwany = pom->nast;
		pom->nast = usuwany->nast;

		if (usuwany == koniec)
		{
			koniec = pom;
		}
		delete usuwany;
		return true;
	}

	int wielkoscListy() {
		Element<T>* pom = poczatek;
		int ilosc = 0;
		while (pom != NULL)
		{
			pom = pom->nast;
			ilosc++;
		}
		return ilosc;
	}

	bool zapisz(std::string nazaPliku, void (*zapiszDane)(std::ofstream&, T&))
	{
		std::ofstream plik(nazaPliku);
		if (!plik.good())
		{
			return false;
		}
		int wielkosc = wielkoscListy();
		plik << wielkosc << std::endl;

		Element<T>* element = poczatek;
		for (int i = 0; i < wielkosc; i++)
		{
			zapiszDane(plik, element->dane);
			element = element->nast;
		}

		plik.close();
		return true;
	}

	bool wczytaj(std::string nazaPliku, T(*wczytajDane)(std::ifstream&))
	{
		wyczysc();
		std::ifstream plik(nazaPliku);
		if (!plik.good())
		{
			return false;
		}
		int wielkosc;
		plik >> wielkosc;
		std::string enter;
		getline(plik, enter);

		for (int i = 0; i < wielkosc; i++)
		{
			T dane = wczytajDane(plik);
			dodajNaKoniec(dane);
		}

		plik.close();
		return true;
	}

private:
	void skopiuj(const Lista<T>& lista, Lista<T>* nowalista)
	{
		Element<T>* pom = lista.poczatek;
		if (pom != nullptr)
		{
			Element<T>* nowy = new Element<T>;
			nowy->dane = pom->dane;
			nowy->nast = nullptr;
			nowalista->poczatek = nowy;
			nowalista->koniec = nowy;
			pom = pom->nast;
		}
		else {
			nowalista->poczatek = nullptr;
			nowalista->koniec = nullptr;
			return;
		}

		while (pom != nullptr)
		{
			Element<T>* nowy = new Element<T>;
			nowy->dane = pom->dane;
			nowy->nast = nullptr;
			nowalista->koniec->nast = nowy;
			nowalista->koniec = nowy;
			pom = pom->nast;
		}
	}

	void dodajNaOpowiedniaPozycje(Element<T>*& nowaListaPocz, Element<T>*& nowaListaKoniec, Element<T>* wstawiany, bool (*mniejszy)(T&, T&))
	{
		wstawiany->nast = nullptr;
		if (nowaListaPocz == nullptr)
		{
			nowaListaPocz = wstawiany;
			nowaListaKoniec = wstawiany;
			return;
		}

		if (!mniejszy(nowaListaPocz->dane, wstawiany->dane))
		{
			wstawiany->nast = nowaListaPocz;
			nowaListaPocz = wstawiany;
		}

		Element<T>* pom = nowaListaPocz;
		while (pom->nast != nullptr && mniejszy(pom->nast->dane, wstawiany->dane))
		{
			pom = pom->nast;
		}

		if (pom->nast == nullptr)
		{
			koniec->nast = wstawiany;
			koniec = wstawiany;
		}
		else
		{
			dodajZaElementem(pom, wstawiany);
		}
	}

	void dodajZaElementem(Element<T>* poprzedni, Element<T>* wstawiany)
	{

		Element<T>* nastepny = poprzedni->nast;
		poprzedni->nast = wstawiany;
		wstawiany->nast = nastepny;
	}
};