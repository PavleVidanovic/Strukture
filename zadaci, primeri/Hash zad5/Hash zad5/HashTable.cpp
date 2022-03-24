#include "HashTable.h"


HashTable::HashTable()
{
	size = 0;
	niz = NULL;
}


HashTable::~HashTable()
{
	delete[] niz;
}

HashTable::HashTable(int s)
{
	size = s;
	niz = new KeyWord[(int)(1.2*size)];
	for (int i = 0; i < (int)(1.2*size); i++)
		niz[i] = NULL;
}

void HashTable::insert(KeyWord& k)
{
	int indeks = f(k.key);
	if (niz[indeks] != NULL)
	{
		int i = size + 1;
		while (niz[i] != NULL)
		{
			i++;
		}
		if (i < (int)(1.2*size))
			niz[i] = k;
		else
			throw "Niz je pun";
	}
	else
	{
		niz[indeks] = k;
	}
}

KeyWord& HashTable::find(char* c)
{
	int indeks = f(c);
	if (strcmp(niz[indeks].key, c) == 0)
		return niz[indeks];
	else
	{
		int i = size + 1;
		while (strcmp(niz[i].key, c) != 0 && i<(int)(1.2*size))
		{
			i++;
		}
		if (strcmp(niz[i].key, c) == 0)
			return niz[i];
		else
			throw "Ovaj korisnik nije nadjen";
	}
}

int HashTable::f(char* c)
{
	int sum = 0;
	int i = 0;
	while (c[i] != '\0')
	{
		sum = sum + c[i];
		i++;
	}
	return (23*sum)%size;
}
void HashTable::printAll()
{
	for (int i = 0; i < (int)(1.2*size); i++)
	{
		if (niz[i] != NULL)
			niz[i].print();
	}
}
