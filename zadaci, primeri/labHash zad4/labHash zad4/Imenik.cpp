#include "Imenik.h"


Imenik::Imenik()
{
	niz = NULL;
	size = 0;
}


Imenik::~Imenik()
{
	delete[]niz;
}

Imenik::Imenik(int s)
{
	size = s;
	niz = new Korisnik[s];
	for (int i = 0; i < size; i++)
		niz[i] = NULL;
}

int Imenik::f(int t)
{
	return t%size;
};

void Imenik::printAll()
{
	for (int i = 0; i < size; i++)
	{
		if (niz[i] != NULL)
			niz[i].print();
	}
};

Korisnik& Imenik::find(Korisnik& k)
{
	int indeks = f(k.telefon);
	if (niz[indeks] != NULL)
	{
		int i = indeks;
		while (strcmp(niz[i].ime, k.ime)!=0)
		{
			i = niz[i].next;
		}
		if (strcmp(niz[i].ime, k.ime)==0)
			return niz[i];

		else
			throw "Taj korisnik ne postoji na telefonskom spisku";
	}
	else
		throw "Taj korisnik ne postoji na telefonskom spisku";
};

void Imenik::insert(Korisnik &k)
{
	int indeks = f(k.telefon);
	if (niz[indeks] != NULL)
	{
		int i = indeks + 1;
		while (niz[i] != NULL && i<size)
		{
			i++;
		}
		if (i < size)
		{
			niz[i] = k;
			niz[indeks].next = i;
		}
		else
			throw "Niz je pun";

	}
	else
		niz[indeks] = k;
};