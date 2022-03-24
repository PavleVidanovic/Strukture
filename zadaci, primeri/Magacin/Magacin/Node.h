#pragma once
#include "iostream"
using namespace std;


class Node
{
public:
	int info;
	Node* next;
public:
	Node(){ next = NULL; info = NULL; }
	void print(){ cout << info << " -> "; }
};