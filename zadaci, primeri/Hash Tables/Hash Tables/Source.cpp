#pragma once
#include "HashTable.h"
#include "KeyWords.h"


void main()  
{
	HashTable tablica(10);
	KeyWords f1("for", 0);
	KeyWords f3("while", 5);
	KeyWords f2("do", 1);
	tablica.insert(&f1);
	tablica.insert(&f2);
	tablica.insert(&f3);
	tablica.printAll();
}