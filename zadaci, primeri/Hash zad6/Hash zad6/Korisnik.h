#pragma once
#include "iostream"
#include "string.h"
using namespace std;


class Korisnik
{
public:
	Korisnik(){ JMBG = NULL; ime = NULL; next = NULL; }
	~Korisnik(){}
	Korisnik(Korisnik& k)
	{ 
		next = k.next;
		JMBG = new char[strlen(k.JMBG) + 1];
		strcpy(JMBG, k.JMBG);
		ime = new char[strlen(k.ime) + 1]; 
		strcpy(ime, k.ime); 
	}
	Korisnik(char* br, char* a)
	{ 
		next = NULL; 
		JMBG = new char[strlen(br) + 1];
		strcpy(JMBG, br);
		ime = new char[strlen(a) + 1];
		strcpy(ime, a); 
	}
	void print(){ cout << "Ime korisnika: " << ime << "  Broj JMBGa: " << JMBG << endl; }
	void operator =(int i){ JMBG = NULL; next = NULL; ime = NULL; }
	bool operator !=(int k)
	{
		if (JMBG != NULL || ime != NULL)
			return true;
		else
			return false;
	}
	Korisnik& operator =(Korisnik& k)
	{
		next = k.next;
		JMBG = new char[strlen(k.JMBG) + 1];
		strcpy(JMBG, k.JMBG);
		ime = new char[strlen(k.ime) + 1];
		strcpy(ime, k.ime);
		return *this;
	}
public:
	char* JMBG;
	char* ime;
	int next;
};