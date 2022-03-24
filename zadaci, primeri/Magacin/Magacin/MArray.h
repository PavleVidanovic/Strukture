#pragma once
#include "iostream"
using namespace std;


class MArray
{
private:
	int* niz;
	int dim;
	int* faktori;
	int* dimenzije;
public:
	MArray(){ niz = NULL; dim - NULL; faktori = NULL; dimenzije = NULL; }
	MArray(int m)
	{
		dim = m;
		dimenzije = new int[dim];
		faktori = new int[dim];
		cout << "Unesite sve " << dim << " dimenzije polja" << endl;
		int duzina = 1;
		for (int i = 0; i < m; i++)
			cin >> dimenzije[i];
		for (int i = 0; i < m; i++)
		{
			faktori[i] = duzina;
			duzina = duzina*dimenzije[m - 1 - i];
		}
		niz = new int[duzina];
	}
	void insert(int a)
	{
		cout << "Unesite indekse elementa u nizu";
		int* pom = new int[dim];
		for (int i = 0; i < dim; i++)
			cin >> pom[i];
		int indeks = 0;
		for (int i = 0; i < dim; i++)
			indeks = indeks + faktori[i] * pom[dim - 1 - i];
		niz[indeks] = a;
	}
	int vrati(int* indeksi)
	{
		int ind = 0;
		for (int i = 0; i < dim; i++)
			ind = ind + faktori[i] * indeksi[dim - 1 - i];
		return niz[ind];
	}
};