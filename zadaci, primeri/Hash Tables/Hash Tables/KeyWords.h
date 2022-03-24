#pragma once
#include "iostream"
#include "string.h"
using namespace std;


class KeyWords
{
public:
	KeyWords(){ value = NULL; key = NULL; next = NULL; }
	~KeyWords(){};
	KeyWords(char* m, int k){ key = new char[strlen(m) + 1]; value = k; strcpy(key, m); next = NULL; }
	bool equalKey(char* p){ return !strcmp(p, key);}
	void print(){ cout << value << " " << key << endl; }
	void operator =(int k){ value = k; key = NULL; next =NULL; }
	bool operator !=(int k){ return (value != NULL || key != NULL || next != NULL); }
	KeyWords operator =(KeyWords m){ value = m.value; next = m.next; key = new char[strlen(m.key) + 1]; strcpy(key, m.key); return *this; }
public:
	char* key;
	int value; // iskreno pojama nemam za sta ce mi ovo
	KeyWords* next;
};

