#pragma once
#include "Array.h"
#include "String.h"

void main()
{
	/*  Array<int> niz(5);
	int a, b, c, d, e;
	a = 1;
	b = 2;
	c = 5;
	d = 8;
	e = 12;
	niz.store(0, a);
	niz.store(1, b);
	niz.store(2, c);
	niz.store(3, d);
	niz.store(4, e);
	niz.output();
	int loc = niz.arrayBinarySearch(0, 5, d); //prosledjivanje niza????????
	cout << "Vas trazeni element se nalazi na poziciji " << loc << endl;
	int poz = niz.arrayLinearSearch(5, 7);
	if (poz==NULL)
		cout << "Vas trazeni element se NE nalazi u nizu " << endl;
	else
		cout << "Vas trazeni element se nalazi na poziciji " << poz << endl;
	niz.arrayTraversal(0,5);
	cout << "Izvrsava se obilazak niza..." << endl;
	cout << endl;
	cout << "Vas niz nakon obilaska je" << endl;
	niz.output(); */

	String niz;
	niz.input();
	//char s[3];
	//cout << "Unesite podstring" << endl;
	//cin >> s;
	//char* f;
	//f = s;
	//int i = niz.indexing(f);
	//cout << "Vas podniz pocinje na poziciji " << i << endl;
	char* d;
	d = niz.substring(2,5);
	cout << d;
	

}