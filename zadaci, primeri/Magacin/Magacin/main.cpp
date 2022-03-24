#pragma once
#include "Stack.h"
#include "Queue.h"
#include "Node.h"
#include "MArray.h"


void main()
{
	try{
		/*Stack s(15);
		char a[] = "2785";
		char* ptra = a;
		char b[] = "578";
		char* ptrb = b;
		cout << s.addLong(ptra, ptrb) << endl;
		cout << endl;
		cout << endl;

		s.push(5);
		s.push(12);
		s.push(3);
		s.print();

		Queue red;
		red.enqueue(5);
		red.enqueue(10);
		red.enqueue(1);
		red.enqueue(2);
		red.enqueue(9);
		red.enqueue(7);
		red.print();
		cout << endl;
		red.dequeue();
		red.dequeue();
		cout << endl;
		red.print();*/
		MArray D4(4);
		cout << endl;
		D4.insert(78);
		cout << endl;
		int p[] = { 5, 2, 1, 5 };
		int* ptr = p;
		cout << endl;
		cout << D4.vrati(ptr);
		cout << endl;
	}
	catch (char* c)
	{
		cout << c << endl;
	}
}