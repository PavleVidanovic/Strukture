#pragma once
#include "Node.h"



class SparseMatrix
{
public:
	SparseMatrix();
	~SparseMatrix();
	SparseMatrix(int i, int j);
	void setAt(int el, int i, int j);
	int getAt(int i, int j);
	void printAll();
	//void printZero(int a, int b)
	//{
	//	for (int i = a; i < b; i++)
	//		cout << 0 << " ";
	//}
private:
	Node **rows;
	Node **colums;
	int row;
	int col;
};

