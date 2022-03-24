#include "StaticSortList.h"


CStaticSortList::CStaticSortList()
{
	size = 0;
	head = -1;
	lista = nullptr;
}


CStaticSortList::~CStaticSortList()
{
}

CStaticSortList::CStaticSortList(int max)
{
	if (max < 0)
		throw "Velicina lancane liste ne moze biti negativna";
	lista = new Node[max];
	size = max;
	head = -1;
};

void CStaticSortList::addToHead(int info)
{
	if (head == size-1)
		throw "Lista je puna";
	if (head == -1)
	{
		head++;
		int current = head;
		Node temp;
		temp.next = ++current;
		temp.data = info;
		lista[head] = temp;
	}
	else
	{
		Node temp;
		temp.data = info;
		temp.next = -1;
		for (int i = head; i >= 0; i--)
			lista[i + 1] = lista[i];
		lista[0] = temp;
		head++;
		for (int i = 0; i <= head; i++)
			lista[i].next++;
	}

};

void CStaticSortList::printAll()
{
	for (int i = 0; i <= head; i++){
		lista[i].print();
		cout << " -> ";
	}
	cout << "NULL";
	cout << endl;
};

void CStaticSortList::bubbleSort(bool rastuci)
{
	cout << "Ovo je bubbble sort" << endl;
	if (rastuci)
	{
		for (int i = 0; i <= head-1; i++)
		{
			for (int j = i + 1; j <= head; j++)
			{
				if (lista[i].data > lista[j].data)
				{
					int temp = lista[i].data;
					lista[i].data = lista[j].data;
					lista[j].data = temp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i <= head - 1; i++)
		{
			for (int j = i + 1; j <= head; j++)
			{
				if (lista[i].data < lista[j].data)
				{
					int temp = lista[i].data;
					lista[i].data = lista[j].data;
					lista[j].data = temp;
				}
			}
		}
	}
};
