#include "HashTable.h"


HashTable::HashTable()
{
	size = 0;
	niz = NULL;
}

int HashTable::f(char* c)
{
	int result = 0;
	int i = 0;
	while (c[i] != '\0')
	{
		result = result + c[i];
		i++;
	}
	return (result%size);
};

HashTable::~HashTable()
{
	delete[]niz;
}

HashTable::HashTable(int s)
{
	size = s;
	niz = new KeyWord[s];
	//for (int i = 0; i < size; i++)
	//	niz[i] = NULL;
};

void HashTable::printAll()
{
	for (int i = 0; i < size; i++)
	{
		if (niz[i] != NULL)
			niz[i].print();
	}
};

KeyWord HashTable::find(char* c)
{
	int indeks = f(c);
	return niz[indeks];
};

void HashTable::insert(KeyWord k)
{
	int indeks = f(k.key);
	if (niz[indeks] != NULL)
	{
		int i = indeks + 1;
		while (niz[i] != NULL)
		{
			i++;
		}
		if (i < size)
			niz[i] = k;
		else 
		{
			int i = 0;
			while (niz[i] != NULL)
			{
				i++;
			}
			if (i < size)
				niz[i] = k;
			else
				throw "Nema nesta u nizu";
		}
		
	}
	else
		niz[indeks] = k;
};
