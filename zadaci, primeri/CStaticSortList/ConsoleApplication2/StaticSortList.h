#pragma once
#pragma once
#include "Node.h"


class CStaticSortList
{
public:
	CStaticSortList();
	CStaticSortList(int max);
	~CStaticSortList();
	void addToHead(int info);
	void printAll();
	void bubbleSort(bool rastuci);
	bool isEmpty()
	{
		return (head == -1);
	}
public:
	Node* lista;
	int size;
	int head;
};

