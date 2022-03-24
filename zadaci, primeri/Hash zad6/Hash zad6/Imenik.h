#pragma once
#include "Korisnik.h"


class Imenik
{
public:
	Imenik();
	~Imenik();
	Imenik(int s);
	int f(Korisnik& k);
	void printAll();
	Korisnik& find(Korisnik& k);
	void insert(Korisnik &k);
public:
	Korisnik* niz;
	int size;
};

