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
	niz = new Korisnik[(int)(1.2*size)];
	for (int i = 0; i < (int)(1.2*size); i++)
		niz[i] = NULL;
}

int Imenik::f(Korisnik& k)
{
	int s = 0;
	int j = strlen(k.JMBG) - 6;
	while (k.JMBG[j]!='\0')
	{
		s = s * 10;
		s = s + (k.JMBG[j] - '0');
		j++;
	}
	return s%size;
};

void Imenik::printAll()
{
	for (int i = 0; i < (int)(1.2*size); i++)
	{
		if (niz[i] != NULL)
			niz[i].print();
	}
};

Korisnik& Imenik::find(Korisnik& k)
{
	int indeks = f(k);
	if (strcmp(niz[indeks].ime, k.ime) == 0 && niz[indeks] != NULL)
		return niz[indeks];
	int i = indeks;
	while (strcmp(niz[i].ime, k.ime) != 0)
	{
		i = niz[i].next;
	}
	if (strcmp(niz[i].ime, k.ime) == 0)
		return niz[i];

	else
		throw "Taj korisnik ne postoji na spisku";
};

void Imenik::insert(Korisnik &k)
{
	int indeks = f(k);
	if (niz[indeks] != NULL)
	{
		int i = size + 1;
		while (niz[i] != NULL && i<(int)(1.2*size))
		{
			i++;
		}
		if (i < (int)(1.2*size))
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
