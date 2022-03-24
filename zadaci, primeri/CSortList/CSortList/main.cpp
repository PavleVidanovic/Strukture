#pragma once
#include "Node.h"
#include "SortList.h"


void main()
{
	CSortList lista;
	lista.addToHead(5);
	lista.addToHead(8);
	lista.addToHead(2);
	lista.addToHead(12);
	lista.printAll();
	lista.BubbleSort(true);
	lista.printAll();
}