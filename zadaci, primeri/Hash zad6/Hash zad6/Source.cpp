#pragma once
#include "Imenik.h"
#include "Korisnik.h"

void main()
{
	try
	{
		Imenik tablica(1500);
		Korisnik k1("2803199773368", "Anka");
		Korisnik k2("0801199573367", "Mila");
		Korisnik k3("2801199878329", "Pera");
		Korisnik k4("1810269878125", "Laza");
		Korisnik k5("2705459871925", "Mika");
		tablica.insert(k1);
		tablica.insert(k2);
		tablica.insert(k3);
		tablica.insert(k4);
		tablica.insert(k5);
		tablica.find(k2).print();
		tablica.printAll();
		cout << endl;
	}
	catch (char *c)
	{
		cout << c << endl;
	}

}