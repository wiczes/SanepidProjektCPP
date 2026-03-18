#include "Pacjent.h"
#include <iomanip>
#include <string>
#include <fstream>


Pacjent::Pacjent()
{
	imie = "-";
	nazwisko = "-";
	adres = "-";
	dataKoncaKwarantanny = { 0,0,0 };
}

bool Pacjent::mniejszy(Pacjent& p1, Pacjent& p2)
{
	Data d1 = p1.dataKoncaKwarantanny;
	int data1 = (d1.rok * 100 + d1.miesiac) * 100 + d1.dzien;
	Data d2 = p2.dataKoncaKwarantanny;
	int data2 = (d2.rok * 100 + d2.miesiac) * 100 + d2.dzien;
	return data1 < data2;
}

void Pacjent::wczytajDane()
{
	std::cout << "podaj imie:";
	std::cin >> imie;
	std::cout << "podaj nazwisko:";
	std::cin >> nazwisko;
	std::string enter;
	std::getline(std::cin, enter);
	std::cout << "podaj adres:";
	std::getline(std::cin, adres);
	std::cout << "podaj dzien zakonczenia kwarantanny:";
	std::cin >> dataKoncaKwarantanny.dzien;
	std::cout << "podaj miesiac zakonczenia kwarantanny:";
	std::cin >> dataKoncaKwarantanny.miesiac;
	std::cout << "podaj rok zakonczenia kwarantanny:";
	std::cin >> dataKoncaKwarantanny.rok;
}

void Pacjent::wypiszDaneDoTabeli(int numer)
{
	std::cout << "| " << std::setw(3) << std::setfill(' ') << numer;
	std::cout << " | " << std::setw(10) << std::setfill(' ') << std::left << imie;
	std::cout << " | " << std::setw(10) << std::setfill(' ') << std::left << nazwisko;
	std::cout << " | " << std::setw(25) << std::setfill(' ') << std::left << adres;
	std::cout << " | " << std::setw(2) << std::setfill('0') << std::right << dataKoncaKwarantanny.dzien;
	std::cout << "-" << std::setw(2) << std::setfill('0') << std::right << dataKoncaKwarantanny.miesiac;
	std::cout << "-" << dataKoncaKwarantanny.rok << "     |" << std::endl;
}

bool Pacjent::zawieraText(std::string text)
{
	return imie.find(text) != std::string::npos
		|| nazwisko.find(text) != std::string::npos
		|| adres.find(text) != std::string::npos;
}

bool Pacjent::zawieraDate(Data data)
{
	Data d = dataKoncaKwarantanny;
	return  d.dzien == data.dzien && d.miesiac == data.miesiac && d.rok == data.rok;
}

void Pacjent::zapisz(std::ofstream& plik, Pacjent& pacjent)
{
	plik << pacjent.imie << " ";
	plik << pacjent.nazwisko << std::endl;
	plik << pacjent.adres << std::endl;
	plik << pacjent.dataKoncaKwarantanny.dzien << " ";
	plik << pacjent.dataKoncaKwarantanny.miesiac << " ";
	plik << pacjent.dataKoncaKwarantanny.rok << std::endl;
}

Pacjent Pacjent::wczytaj(std::ifstream& plik)
{
	Pacjent pacjent;
	std::string enter;
	plik >> pacjent.imie;
	plik >> pacjent.nazwisko;
	std::getline(plik, enter);
	std::getline(plik, pacjent.adres);
	plik >> pacjent.dataKoncaKwarantanny.dzien;
	plik >> pacjent.dataKoncaKwarantanny.miesiac;
	plik >> pacjent.dataKoncaKwarantanny.rok;

	return pacjent;
}