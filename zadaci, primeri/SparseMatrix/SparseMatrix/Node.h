#pragma once
#pragma once
#include "iostream"
using namespace std;

class Node
{
public:
	Node();
	~Node();
	void print()
	{
		cout << data << " ";
	}
public:
	int data;
	int row_position;
	int column_postion;
	Node *nextRow;
	Node *nextColumn;
};

