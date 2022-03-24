#pragma once
#include "HashTable.h"
#include "KeyWord.h"


void main()
{
	try
	{

		HashTable tablica(10);
		KeyWord k1("for", 5);
		KeyWord k2("while", 3);
		KeyWord k3("do", 8);
		//KeyWord k4("if", 8);
		KeyWord k5("else", 5);
		tablica.insert(k1);
		tablica.insert(k2);
		tablica.insert(k3);
		//tablica.insert(k4);
		tablica.insert(k5);
		tablica.printAll();
		tablica.find("while").print();
	}
	catch (char* c)
	{
		cout << c << endl;
	}
}