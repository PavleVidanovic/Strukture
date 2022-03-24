#pragma once
#include "KeyWords.h"


class HashTable
{
public:
	HashTable();
	~HashTable();
	HashTable(int s);
	int f(char* s);
	void insert(KeyWords* k);
	KeyWords find(char* c);
	void printAll();
public:
	KeyWords** hashArray;
	int size;
	int current;
};

