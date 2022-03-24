#pragma once
#include "iostream"
#include "string.h"
using namespace std;


class Korisnik
{
public:
	Korisnik(){ telefon = NULL; ime = NULL; next = NULL; }
	~Korisnik(){}
	Korisnik(Korisnik& k){ next = k.next; telefon = k.telefon; ime = new char[strlen(k.ime) + 1]; strcpy(ime, k.ime); }
	Korisnik(int br, char* a){ next = NULL; telefon = br; ime = new char[strlen(a) + 1]; strcpy(ime, a); }
	void print(){ cout << "Ime korisnika: " << ime << "  Broj telefona: " << telefon << endl; }
	void operator =(int k){ telefon = k; next = NULL; ime = NULL; }
	bool operator !=(int k)
	{
		if (telefon != k || ime != NULL)
			return true;
		else
			return false;
	}
	Korisnik& operator =(Korisnik& k){ next = k.next; telefon = k.telefon; ime = new char[strlen(k.ime) + 1]; strcpy(ime, k.ime); return *this; }
public:
	int telefon;
	char* ime;
	int next;
};