#pragma once
#include "iostream"
#include "string.h"
#include <iomanip>
using namespace std;


class Pretplatnici
{
public:
	Pretplatnici(){ key = NULL; next = NULL; ime = NULL; }
	~Pretplatnici(){};
	Pretplatnici(int k, char* im){ next = NULL; ime = new char[strlen(im) + 1]; strcpy(ime,im); key = k; }
	void print(){ cout << "Ime pretplatnika" << setw(10) << ime << "   Broj.tel: (+381)" << key << endl; }
public:
	char* ime;
	int key;
	Pretplatnici* next;

};

