#pragma once
#include "KeyWord.h"


class HashTable
{
public:
	HashTable();
	~HashTable();
	HashTable(int s);
	void insert(KeyWord& k);
	KeyWord& find(char* c);
	int f(char* c);
	void printAll();
public:
	KeyWord* niz;
	int size;
};

