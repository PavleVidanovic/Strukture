#pragma once
#include "Node.h"
#include "StaticSortList.h"


void main()
{
	try
	{
		CStaticSortList lista(5);


		lista.addToHead(5);
		lista.addToHead(6);
		lista.addToHead(7);
		lista.addToHead(8);
		lista.addToHead(10);

		lista.printAll();

		lista.bubbleSort(true);

		lista.printAll();
	}
	catch (char* c)
	{
		cout << c << endl;
	}
}