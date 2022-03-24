#pragma once
#include "Node.h"
#include "StaticSortDL.h"

void main()
{
	try
	{
		CStaticSortDL lista(5);

		lista.addToHead(5);
		lista.addToHead(1);
		lista.addToHead(8);
		lista.addToHead(2);
		lista.addToHead(11);

		lista.printAll();
		
		lista.bubbleSort(true);
		
		lista.printAll();

		lista.bubbleSort(false);

		lista.printAll();
	}
	catch (char* c)
	{
		cout << c << endl;
	}
}