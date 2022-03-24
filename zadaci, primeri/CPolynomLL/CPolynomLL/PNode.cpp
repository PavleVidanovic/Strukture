#include "PNode.h"


PNode::PNode()
{
	exponent = NULL;
	coeff = NULL;
	next = NULL;
}


PNode::~PNode()
{
}

void PNode::setExp(int e)
{
	exponent = e;
};


void PNode::setCoeff(double c)
{
	coeff = c;
};

void PNode::setNext(PNode* p)
{
	next = p;
};

void PNode::print()
{
	cout << " " << coeff << "*x^" << exponent << " ";
};
