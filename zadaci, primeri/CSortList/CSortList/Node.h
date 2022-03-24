#pragma once
#include "iostream"
using namespace std;

class Node
{
public:
	Node();
	~Node();
	void setNext(Node* n)
	{
		next = n;
	}
	void setData(int info)
	{
		data = info;
	}
	inline int returnData()
	{
		return data;
	}
	inline Node* returnNext()
	{
		return next;
	}
	void print()
	{
		cout << "Data: " << data << " ";
	}
private:
	int data;
	Node* next;
};

