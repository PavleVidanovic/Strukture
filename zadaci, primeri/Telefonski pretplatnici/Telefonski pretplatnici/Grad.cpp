#include "Grad.h"


Grad::Grad()
{
	size = 0;
	niz = NULL;
}


Grad::~Grad()
{
	delete[]niz;
}

Grad::Grad(int s)
{
	size = s;
	niz = new Pretplatnici*[s];
	for (int i = 0; i < size; i++)
		niz[i] = NULL;
}

int Grad::f(int k)
{
	return (k%size);
}

Pretplatnici Grad::find(int k)
{
	int index = f(k);
	if (niz[index]->key != NULL)
		throw "Taj element ne postoji u nizu";
	return *niz[index];

}

void Grad::printAll()
{
	for (int i = 0; i < size; i++)
	{
		if (niz[i] != NULL)
		{
			if (niz[i]->next == NULL)
				niz[i]->print();
			else
			{
				Pretplatnici* tmp = niz[i]->next;
				while (tmp != NULL)
				{
					tmp->print();
					tmp = tmp->next;
				}
			}
		}
	}
}

void Grad::insert(Pretplatnici* p)
{
	int index = f(p->key);
	p->next = NULL;
	if (niz[index] != NULL)
	{
		if (niz[index]->next == NULL)
			niz[index]->next = p;
		else
		{
			Pretplatnici* tmp = niz[index]->next;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = p;
		}
	}
	else
		niz[index] = p;
}
