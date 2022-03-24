#include "Stablo.h"


Stablo::Stablo()
{
}

Stablo::Stablo(int size)
{
	n = size;
	niz = new Node[n];
	root = -1;
}



Stablo::~Stablo()
{
}

void Stablo::print()
{
	for (int i = 0; i < n; i++)
	{
		if (niz[i].data != NULL)
			cout << niz[i].data << " ";
		else
			cout << " prazno ";
	}
}

int Stablo::visina()
{
	return visina(0);
}
int Stablo::visina(int p)
{
	
}

int Stablo::brojRaz()
{
	int* arr = new int[n];
	int trenutno = 0;
	for (int i = 0; i < n; i++)
	{
		if (niz[i].data != NULL)
		{
			if (trenutno==0)
				arr[trenutno++] = niz[i].data;
			else
			{
				int j = 0;
				while (arr[j] != niz[i].data && j < trenutno)
					j++;
				if (j == trenutno)
					arr[trenutno++] = niz[i].data;
			}
		}
			
	}
	return trenutno;

}

void Stablo::insert(int value)
{
	Node p;
	p.data = value;
	p.left = -1;
	p.right = -1;
	if (root == -1)
	{
		niz[0] = p;
		root = 0;
	}
	else
	{
		int i = 0;
		while (i < n && niz[i].left != -1 && niz[i].right != -1)
		{
			i = i + 3;
		}
		if (niz[i].left == -1)
		{
			if (niz[i].data == NULL)
			{
				niz[i] = p;
			}
			else
			{
				if (niz[i].data == NULL)
				{
					niz[i] = p;
				}
				else
				{
					niz[i].left = 2 * i + 1;
					niz[2 * i + 1] = p;
				}
			}
			
		}
		else if (niz[i].right == -1)
		{
			niz[i].right = 2 * i + 2;
			niz[2 * i + 2] = p;
		}
	}

}
