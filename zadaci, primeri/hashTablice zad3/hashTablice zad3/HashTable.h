#pragma once
#include "KeyWord.h"


class HashTable
{
public:
	HashTable();
	~HashTable();
	HashTable(int s);
	void printAll();
	KeyWord find(char* c);
	void insert(KeyWord k);
	int f(char* c);
public:
	int size;
	KeyWord* niz;
};

