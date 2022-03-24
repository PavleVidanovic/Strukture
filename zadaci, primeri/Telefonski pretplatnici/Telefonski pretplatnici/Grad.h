#pragma once
#include "Pretplatnici.h"


class Grad
{
public:
	Grad();
	~Grad();
	Grad(int s);
	int f(int k);
	Pretplatnici find(int k);
	void printAll();
	void insert(Pretplatnici* p);
public:
	int size;
	Pretplatnici **niz;
	
};

