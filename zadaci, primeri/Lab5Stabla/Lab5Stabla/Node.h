#pragma once
#include "iostream"
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int d)
	{
		left = NULL;
		right = NULL;
		data = d;
	}
	Node()
	{
		left = NULL;
		right = NULL;
		data = NULL;
	}
	void visit()
	{
		cout << "Element je posecen" << endl;
		cout << data << endl;
	}

};