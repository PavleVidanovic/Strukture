#pragma once
#include "iostream"
#include "string.h"
using namespace std;


class KeyWord
{
public:
	KeyWord(){ key = NULL; value = NULL; }
	KeyWord(char* c, int k){ value = k; key = new char[strlen(c) + 1]; strcpy(key, c); }
	~KeyWord(){ }
	void print(){ cout << "Value: " << value << "  Keyword: " << key << endl; }
	void operator=(int k){ key = NULL; value = k; }
	bool operator !=(int k){ return (key != NULL || value != k); }
	KeyWord operator =(KeyWord k){ key = new char[strlen(k.key) + 1]; strcpy(key, k.key); value = k.value; return *this; }
public:
	int value;
	char* key;
};