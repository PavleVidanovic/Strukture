#pragma once
#include "PNode.h"

class CPolynomLL
{
public:
	CPolynomLL();
	~CPolynomLL();
	void Coeff(int exp, double coef);
	CPolynomLL add(CPolynomLL poly1, CPolynomLL poly2);
	void printAll();
	bool search(int expo, double coef);
	CPolynomLL mul(CPolynomLL poly1, CPolynomLL poly2);
private:
	PNode* head;
};

