#include "PolynomLL.h"


CPolynomLL::CPolynomLL()
{
	head = NULL;
}


CPolynomLL::~CPolynomLL()
{
}

void CPolynomLL::Coeff(int expo, double coef)   //  void addToHead(int exp,double coef) ???
{
	
	if (head == NULL)
	{
		PNode* temp = new PNode();
		temp->setCoeff(coef);
		temp->setExp(expo);
		temp->setNext(NULL);
		head = temp;
	}
	else
	{
		PNode* temp2 = head;
		PNode* temp = new PNode();
		temp->setCoeff(coef);
		temp->setExp(expo);
		temp->setNext(temp2);
		head = temp;
	}
};

bool CPolynomLL::search(int expo, double coef)
{
	PNode* temp = new PNode();
	temp = head;
	while (temp != NULL){
		if (temp->returnCoeff() == coef && temp->returnExp() == expo)
			return true;
		temp = temp->returnNext();
	}
	return false;
};

CPolynomLL CPolynomLL::add(CPolynomLL poly1, CPolynomLL poly2) 
{
	CPolynomLL united;
	PNode* temp1;
	bool p = false;
	PNode* temp2 = poly2.head;
	for (temp1 = poly1.head; temp1 != NULL;temp1=temp1->returnNext())
	{
		while (temp2 != NULL)
		{
			if (temp2->returnExp() == temp1->returnExp())
			{
				united.Coeff(temp1->returnExp(), temp1->returnCoeff() + temp2->returnCoeff());
				p = true;
			}
			temp2 = temp2->returnNext();
		}
		if (!p)
			united.Coeff(temp1->returnExp(), temp1->returnCoeff());
		temp2 = poly2.head;
		p = false;
	}
	temp1 = poly1.head;
	p = false;
	for (temp2 = poly2.head; temp2 != NULL; temp2 = temp2->returnNext())
	{
		while (temp1 != NULL)
		{
			if (temp1->returnExp() == temp2->returnExp())
			{
				p = true;
			}
			temp1 = temp1->returnNext();
		}
		if (!p)
			united.Coeff(temp2->returnExp(), temp2->returnCoeff());
		temp1 = poly1.head;
		p = false;
	}

	return united;
};

void CPolynomLL::printAll()
{
	PNode* temp = head;
	while (temp->returnNext()!= NULL)
	{
		
		temp->print();
		cout << "+";
		temp = temp->returnNext();
	}
	temp->print();
	cout << endl;
};

CPolynomLL CPolynomLL::mul(CPolynomLL poly1, CPolynomLL poly2)
{
	PNode* temp1 = poly1.head;
	PNode* temp2;
	CPolynomLL united;
	CPolynomLL MUL;
	while (temp1 != NULL)
	{
		for (temp2 = poly2.head; temp2 != NULL; temp2 = temp2->returnNext())
			united.Coeff(temp1->returnExp() + temp2->returnExp(), temp1->returnCoeff()*temp2->returnCoeff());
		temp1 = temp1->returnNext();
	}
	temp1 = united.head;
	temp2 = united.head;
	bool b = false;
	while (temp1 != NULL)
	{
		while (temp2!=NULL)
		{
			if (temp1 != temp2)
			{
				if (temp1->returnExp() == temp2->returnExp()){
					if (MUL.search(temp1->returnExp(), temp1->returnCoeff() + temp2->returnCoeff())==false) //uslov da se ne dupliraju sabrani clanovi
					{
						MUL.Coeff(temp1->returnExp(), temp1->returnCoeff() + temp2->returnCoeff());
						b = true;
					}
					if (MUL.search(temp1->returnExp(), temp1->returnCoeff() + temp2->returnCoeff())) //uslov da se eksponenti vec sabranih clanova ne stavljaju u LL
						b = true;
				}
			}
			temp2 = temp2->returnNext();
		}
		if (!b && MUL.search(temp1->returnExp(),temp1->returnCoeff())==false)
		{
			MUL.Coeff(temp1->returnExp(), temp1->returnCoeff());
		}
		temp2 = united.head;
		b = false;
		temp1 = temp1->returnNext();
	}
	return MUL;
};
