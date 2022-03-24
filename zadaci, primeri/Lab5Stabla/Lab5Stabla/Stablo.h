#pragma once
#include "Node.h"
class Stablo
{
	
public:
	Stablo(){ root = NULL; numberOfElements = 0; trenutno = 0; }
	~Stablo();
	void insert(int d);
	void print(Node* p);
	int findMin();
	int findMax();
	int brojEl(Node* p);
	int findMinRec(Node* r);
	int findMaxRec(Node* r);
	int brojRazlicitih();
	int prebrojiLeve(Node* p);
	void deleteAll(Node* p);
	int nivoMax(Node* p);
	bool isBTS(Node* p);
	void insertNoBTS(int value, Node* p);
	Stablo* sortedArrayToBTS(int a[],int n);
	bool search(Node* p,int value,Node* smesti);
	Node* returnRoot()
	{
		return root;
	}
	bool isEmpty()
	{
		if (root == NULL)
			return true;
		else
			return false;
	}
	void stampajNiz()
	{
		for (int i = 0; i < trenutno; i++)
			cout << niz[i] << " ";
		cout << endl;
	}
	void napraviNiz();
	void popuniNiz(Node*  p);
	int findHight(Node* r);
	int tezina(Node* r);
private:
	Node* root;
	int numberOfElements;
	int trenutno;
	int* niz;
	
};

