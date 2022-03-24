#pragma once
#include "iostream"
using namespace std;


class Node
{
public:
	Node();
	~Node();
	void setData(int k);
	void setNext(Node* k);
	void print();
	int returnData();
	Node* returnNode();
private:
	int data;
	Node* next;
};

