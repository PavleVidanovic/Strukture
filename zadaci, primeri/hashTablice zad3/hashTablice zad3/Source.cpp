#pragma once
#include "HashTable.h"
#include "KeyWord.h"


void main()
{
	try
	{
		KeyWord k1("for", 0);
		KeyWord k2("do", 1);
		KeyWord k3("while", 1);
		KeyWord k4("sizeof", 1);
		KeyWord k5("for", 100);
		KeyWord k6("for", 101);
		HashTable tablica(10);
		tablica.insert(k1);
		tablica.insert(k2);
		tablica.insert(k3);
		tablica.insert(k4);
		tablica.insert(k5);
		tablica.insert(k6);
		tablica.printAll();
	}
	catch (char *c)
	{
		cout << c;
	}
}