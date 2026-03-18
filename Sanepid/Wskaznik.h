#pragma once
#ifndef WSKAZNIK_H
#define WSKAZNIK_H


template<typename T> class Lista;
template<typename T> struct Element;

template<typename T>
class Wskaznik
{
private:
	Element<T>* poprzedni;
	Element<T>* wskazywany;

private:
	Wskaznik(){}
public:
	T operator*() const {
		return wskazywany->dane;
	}

	bool operator!=(const Wskaznik<T>& wsk) const {
		return poprzedni != wsk.poprzedni && wskazywany != wsk.wskazywany;
	}
	Wskaznik<T>& operator++();

	Wskaznik<T> operator++(int) {
		Wskaznik<T> temp = *this;
		++(*this);
		return temp;
	}

	Wskaznik<T>& operator+=(const int ilePrzesunac) {
		for (int i = 0; i < ilePrzesunac; i++)
		{
			(*this)++;
		}
		return *this;
	}

	friend class Lista<T>;
};

template<typename T>
Wskaznik<T>& Wskaznik<T>::operator++() {
	if (wskazywany != nullptr)
	{
		poprzedni = wskazywany;
		wskazywany = wskazywany->nast;
	}
	return *this;
}

#endif 