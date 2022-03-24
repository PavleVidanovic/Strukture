#pragma once
#include "Node.h"


class CSortList
{
public:
	CSortList();
	~CSortList();
	void BubbleSort(bool sort);
	void InsertionSort(bool sort);
	void SelectionSort(bool sort);
	void addToHead(int info);
	void printAll();

	Node* returnHead()
	{
		return head;
	}
	

	Node* before(Node *n)
	{
		if (n == head)
			return NULL;
		else
		{
			Node* temp;
			for (temp = head; temp->returnNext() != n; temp = temp->returnNext());
			return temp;
		}
	}

	void swap(Node* prev1, Node* ptr1, Node* prev2, Node* ptr2)
	{
		if (ptr2 == NULL || ptr1 == NULL)
			return;
		Node* temp1 = ptr1->returnNext();
		Node* temp2 = ptr2->returnNext();
		if (prev1 == NULL)
		{
			head = ptr2;
			ptr2->setNext(temp1);
			ptr1->setNext(temp2);
			prev2->setNext(ptr1);
		}
		else if (prev2 == NULL)
		{
			head = ptr1;
			ptr2->setNext(temp1);
			ptr1->setNext(temp2);
			prev1->setNext(ptr2);
		}
		else
		{
			ptr2->setNext(temp1);
			ptr1->setNext(temp2);
			prev2->setNext(ptr1);
			prev1->setNext(ptr2);
		}

	}

	void swapNeighbor(Node* prev, Node* ptr)
	{
		if (before(prev) != NULL)
		{
			Node* temp1 = ptr->returnNext();
			Node* temp2 = prev;
			prev->setNext(temp1);
			ptr->setNext(prev);
			before(temp2)->setNext(ptr);
		}
		else
		{
			Node* temp1 = ptr->returnNext();
			Node* temp2 = prev;
			prev->setNext(temp1);
			head = ptr;
			ptr->setNext(prev);
		}
	};

private:
	Node* head;
};

