#pragma once
#include <iostream>


struct Data
{
	int rok;
	int miesiac;
	int dzien;
};

class Pacjent
{
private:
	std::string imie;
	std::string nazwisko;
	std::string adres;
	Data dataKoncaKwarantanny;

public:
	Pacjent();

	static bool mniejszy(Pacjent& p1, Pacjent& p2);

	void wczytajDane();

	void wypiszDaneDoTabeli(int numer);

	bool zawieraText(std::string text);

	bool zawieraDate(Data data);

	static void zapisz(std::ofstream& plik, Pacjent& pacjent);

	static Pacjent wczytaj(std::ifstream& plik);
};