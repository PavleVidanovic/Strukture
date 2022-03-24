#pragma once
/*Zad 3. Projektovati klasu za rad sa hash tablicom
sa unutra�njim ulan�avanjem koja slu�i za sme�tanje 
klju�nih re�i programskog jezika C++, bez kori��enja 
posebnog prostora za sme�tanje sinonima. Izabrati
veli�inu tablice i hash funkciju tako da ima �to je
mogu�e bolje rasipanje vrednosti. */
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
	
	HashObject();//STE
	HashObject(char*);//PE
	HashObject(char*,int);//NA
	HashObject(char*, int, int);//STO
	HashObject(HashObject&);
	~HashObject();

	HashObject& operator=(HashObject);
	bool operator==(HashObject obj) { return getKey() == obj.getKey(); }
	char* getKey() { return this->key; }
	int getRecord() { return record; }
	bool isEqualKey(char* s) { return s==getKey(); }//OBRATI PAZNJU!!!
	bool isFree() { return this->free; }
	void print();
	void deleteRecord();


};