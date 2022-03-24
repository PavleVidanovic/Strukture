#pragma once
#include "SLList.h"
#include "SLLNode.h"


void main()
{
	try
	{
		SLList mojalista;
		//SLList mojalista2;
		mojalista.addToHead(8);
		mojalista.addToHead(7);
		mojalista.addToHead(2);
		mojalista.addToHead(4);
		mojalista.addToHead(6);
		mojalista.addToHead(1);
		//mojalista2.addToHead(7);
		//mojalista2.addToHead(6);
		//mojalista2.addToHead(3);
		mojalista.printAll();
		cout << endl;
		//mojalista2.printAll();

		

		cout << endl;
		mojalista.insertionSort();

		mojalista.printAll();
		


		
	}
	catch (char* c)
	{
		cout << c << endl;
	}
	
}