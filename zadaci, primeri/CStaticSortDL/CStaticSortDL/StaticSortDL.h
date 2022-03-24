#pragma once 
#include "Node.h"


class CStaticSortDL
{
public:
	CStaticSortDL();
	~CStaticSortDL();
	CStaticSortDL(int max);
	void addToHead(int info);
	void bubbleSort(bool rastuci);
	void printAll();
public:
	Node* lista;
	int head;
	int size;
	int tail;
};

