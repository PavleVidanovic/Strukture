#pragma once
#include "iostream"
using namespace std;


class Node
{
public:
	int left;
	int right;
	int data;
	Node()
	{
		data = NULL;
		left = -1;
		right = -1;
	}
	Node(int value)
	{
		data = value;
	}
	void visit()
	{
		cout << data << " ";
	}
	Node& operator =(Node p)
	{
		left = p.left;
		right = p.right;
		data = p.data;
		return *this;
	}
};