#include "StaticSortDL.h"


CStaticSortDL::CStaticSortDL()
{
	head = -1;
	tail = -1;
	size = 0;
	lista = nullptr;
}


CStaticSortDL::~CStaticSortDL()
{
	if (lista == nullptr)
		throw "Lista je vec obrisana";
	delete []lista;
}

CStaticSortDL::CStaticSortDL(int max)
{
	if (max < 0)
		throw "Velicina liste mora biti pozitivan broj";
	size = max;
	lista = new Node[max];
	head = -1;
	tail = -1;
};

void CStaticSortDL::addToHead(int info)
{
	if (tail == size - 1)
		throw "Lista je puna";
	if (head == -1)
	{
		head++;
		tail++;
		int current = head + 1;
		Node temp;
		temp.data = info;
		temp.next = current;
		temp.previous = -1;
		lista[head] = temp;
	}
	else
	{
		Node temp;
		temp.data = info;
		temp.next = head;
		temp.previous = -2;
		for (int i = tail; i >= 0; i--)
			lista[i + 1] = lista[i];
		lista[0] = temp;
		for (int i = 0; i <= tail + 1; i++)
		{
			lista[i].next++;
			lista[i].previous++;
		}
		tail++;
		size++;
	}
};

void CStaticSortDL::bubbleSort(bool rastuci)
{
	cout << "Bubble sort" << endl;
	if (rastuci)
	{
		for (int i = 0; i <= tail - 1; i++)
		{
			for (int j = i + 1; j <= tail; j++)
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
		for (int i = 0; i <= tail - 1; i++)
		{
			for (int j = i + 1; j <= tail; j++)
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

void CStaticSortDL::printAll()
{
	for (int i = 0; i <= tail; i++)
	{
		cout << lista[i].previous << " ";
		lista[i].print();
		cout << " " << lista[i].next << " ";
		cout << endl;
	}
};
