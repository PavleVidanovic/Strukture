#pragma once
#include "iostream"
#include "string.h"
using namespace std;


class KeyWord
{
public:
	KeyWord(){ key = NULL; next = NULL; value = NULL; }
	~KeyWord(){}
	KeyWord(char* c, int k){ key = new char[strlen(c) + 1]; strcpy(key, c); next = NULL; value = k; }
	void print(){ cout << "Key word: " << key << "   Value: " << value << endl; }
	void operator =(int k){ key = NULL; next = k; value = k; }
	KeyWord& operator =(KeyWord& k){ key = new char[strlen(k.key) + 1]; strcpy(key, k.key); next = k.next; value = k.value; return *this; }
	bool operator !=(int k)
	{
		if (key != NULL && value != NULL)
			return true;
		else
			return false;
	}
public:
	char* key;
	int value;
	int next;
};

