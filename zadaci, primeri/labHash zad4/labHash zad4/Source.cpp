#pragma once
#include "Imenik.h"
#include "Korisnik.h"

void main()
{
	try
	{
		Imenik tablica(10);
		Korisnik k1(25, "Ana");
		Korisnik k2(35, "Mila");
		Korisnik k3(31, "Pera");
		tablica.insert(k1);
		tablica.insert(k2);
		tablica.insert(k3);
		tablica.find(k2).print();
		tablica.printAll();
		cout << endl;
	}
	catch (char *c)
	{
		cout << c << endl;
	}

}