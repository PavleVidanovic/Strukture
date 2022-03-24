#pragma once
#include "iostream"
using namespace std;

class PNode
{
public:
	PNode();
	~PNode();
	void setExp(int e);
	void setCoeff(double c);
	void setNext(PNode* p);
	inline int returnExp()
	{
		return exponent;
	}
	inline double returnCoeff()
	{
		return coeff;
	}
	inline PNode* returnNext()
	{
		return next;
	}
	void print();
private:
	int exponent;
	double coeff;
	PNode* next;
};

