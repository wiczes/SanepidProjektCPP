#pragma once
#include <iostream>
#include <string>
#include "Lista.h"
#include "Pacjent.h"


class Pacjenci
{
	Lista<Pacjent> lista;

public:
	void dodajPacjenta();

	void wypiszPacjentow();

	void wypiszWedlugDlugosciKwarantanny();

	void wyszukajPoTekscie();

	void wyszukajPoDacie();

	void usunPacjenta();

	void zapisz();

	void wczytaj();

private:
	void wypiszPacjentow(Lista<Pacjent>& lista);

	void WypiszNaglowekTabeli();

	void wypiszLinie();
};

