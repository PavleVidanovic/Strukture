#pragma once
#include "iostream"
#include "Node.h"
using namespace std;

class Queue
{
private:
	Node *head, *tail;
public:
	Queue(){ head = NULL; tail = NULL; }
	void enqueue(int data)
	{
		Node* p = new Node;
		p->info = data;
		p->next = NULL;
		if (tail == NULL)
		{
			head = p;
			tail = p;
		}
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	void dequeue()
	{
		if (head == NULL)
			throw "Red je prazan";
		head = head->next;
	}
	void print()
	{
		Node* tmp = head;
		while (tmp != NULL)
		{
			tmp->print();
			tmp = tmp -> next;
		}
	}
};