#include "SortList.h"


CSortList::CSortList()
{
	head = NULL;
}


CSortList::~CSortList()
{
}

void CSortList::BubbleSort(bool sort)
{
	if (head == NULL || head->returnNext() == NULL)
		return;

	Node* i;
	Node* j;
	Node* previ = NULL;
	Node* prevj;
	int temp;

	if (sort)
	{
		for (i = head; i != NULL; i = i->returnNext())
		{
			prevj = NULL;
			for (j = head; j != NULL; j = j->returnNext())
			{
				if (j != i)
				{
					if (i->returnData() > j->returnData())
					{
						swap(previ, i, prevj, j);
					}
					prevj = j;
				}
			}
			previ = i;
		}
	}
	else
	{
		for (i = head; i->returnNext() != NULL; i = i->returnNext())
		{
			prevj = i;
			for (j = i->returnNext(); j != NULL; j = j->returnNext())
			{
				if (i->returnData() < j->returnData())
				{
					swap(previ, i, prevj, j);
					printAll();
				}
				prevj = j;
			}
			previ = i;
		}
	}
};

void CSortList::InsertionSort(bool sort)
{

};


void CSortList::SelectionSort(bool sort)   // NE RADI
{
	if (head == NULL || head->returnNext() == NULL)
		return;
	
};


void CSortList::addToHead(int info)
{
	if (head == NULL)
	{
		Node* temp = new Node();
		temp->setData(info);
		temp->setNext(NULL);
		head = temp;
	}
	else
	{
		Node* temp = new Node();
		temp->setData(info);
		temp->setNext(head);
		head = temp;

	}
};

void CSortList::printAll()
{
	Node* temp = head;
	while (temp != NULL)
	{
		temp->print();
		cout << endl;
		temp = temp->returnNext();
	}
	cout << endl;
};
