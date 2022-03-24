#pragma once
#include "PNode.h"
#include "PolynomLL.h"


void main()
{
	CPolynomLL lista1;
	lista1.Coeff(2, 1.0);
	lista1.Coeff(3, 4.0);
	lista1.printAll();
	CPolynomLL lista2;
	lista2.Coeff(6, 1.0);
	lista2.Coeff(5, 3.0);
	lista2.printAll();
	CPolynomLL unija;
	unija.add(lista1, lista2).printAll();
	CPolynomLL proizvod;
	proizvod.mul(lista1, lista2).printAll();
}