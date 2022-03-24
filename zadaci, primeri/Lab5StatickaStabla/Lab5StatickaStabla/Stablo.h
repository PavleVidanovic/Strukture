#pragma once
#include "Node.h"
class Stablo
{
	
public:
	Stablo();
	Stablo(int size);
	~Stablo();
	void insert(int value);
	void print();
	int brojRaz();
	int visina();
	int visina(int n);
private:
	Node* niz;
	int n;
	int root;
};

