#pragma once
/*Zad 5. Projektovati klasu za rad sa hash tablicom 
sa unutra�njim ulan�avanjem koja slu�i za sme�tanje
klju�nih re�i programskog jezika C++, sa kori��enjem 
posebnog prostora za sme�tanje sinonima. */
#include<iostream>
using namespace std;
class HashObject 
{
public:
	char* key;
	int record;
	bool free;
	int next;
	
public:
	
	HashObject();
	HashObject(char*);
	HashObject(char*,int);
	HashObject(char*, int, int);
	HashObject(HashObject&);
	~HashObject();

	HashObject& operator=(HashObject);
	bool operator==(HashObject obj) { return getKey() == obj.getKey(); }
	char* getKey() { return this->key; }
	int getRecord() { return record; }
	bool isEqualKey(char* s) { return s==getKey(); }
	bool isFree() { return this->free; }
	void print();
	void deleteRecord();


};