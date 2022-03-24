#pragma once
#include "SLLNode.h"

class SLList
{
public:
	SLList();
	~SLList();
	bool isEmpty();
	void addToHead(int info);
	void addToTail(int info);
	int deleteFromHead();
	void deleteNode(int k);
	void printAll();
	void insertionSort();
	void groupDuplicates();
	void movePartToEnd(int a, int b);
	void update(int v,int add);
	void Insert(int info, int position);
	SLLNode* merge(SLLNode* h1, SLLNode* h2);
	void addInSorted(int e);
	SLLNode* returnHead()
	{
		return head;
	}
	void setHead(SLLNode* h)
	{
		head = h;
	}
	SLLNode* before(SLLNode* n)
	{
		if (n == head)
			return NULL;
		SLLNode* temp;
		for (temp = head; temp->returnLink() != n; temp = temp->returnLink());
		return temp;
	};
	void swapNeighbor(SLLNode* prev, SLLNode* ptr)
	{
		if (before(prev) != NULL)
		{
			SLLNode* temp1 = ptr->returnLink();
			SLLNode* temp2 = prev;
			prev->setLink(temp1);
			ptr->setLink(prev);
			before(temp2)->setLink(ptr);
		}
		else
		{
			SLLNode* temp1 = ptr->returnLink();
			SLLNode* temp2 = prev;
			prev->setLink(temp1);
			head = ptr;
			ptr->setLink(prev);
		}
	};
	SLLNode* returnNode(int info)
	{
		SLLNode* temp = head;
		while (temp != NULL && temp->returnData()!=info)
		{
			temp = temp->returnLink();
		}
		if (temp != NULL)
			return temp;
		else
			return NULL;
	}
	void swap(SLLNode* prev1, SLLNode* ptr1, SLLNode* prev2, SLLNode* ptr2)
	{
		if (ptr2 == NULL || ptr1 == NULL)
			return;
		SLLNode* temp1 = ptr1->returnLink();
		SLLNode* temp2 = ptr2->returnLink();
		if (prev1 == NULL)
		{
			head = ptr2;
			ptr2->setLink(temp1);
			ptr1->setLink(temp2);
			prev2->setLink(ptr1);
		}
		else if (prev2 == NULL)
		{
			head = ptr1;
			ptr2->setLink(temp1);
			ptr1->setLink(temp2);
			prev1->setLink(ptr2);
		}
		else
		{
			ptr2->setLink(temp1);
			ptr1->setLink(temp2);
			prev2->setLink(ptr1);
			prev1->setLink(ptr2);
		}

	}
	void deleteCurrentNode(SLLNode* cvor)
	{
		if (head == NULL)
			throw "Lista je prazna";
		if (before(cvor) == NULL)
		{
			head = cvor->link;
		}
		else
		{
			SLLNode* next = cvor->link;
			before(cvor)->link = next;
			delete cvor;
		}
	}
private:
	SLLNode* head;
	// moze i pokazivac na tail da se implementira

};

