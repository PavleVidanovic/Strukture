#pragma once
#include "SLList.h"


SLList::SLList()
{
	head = NULL;
}


SLList::~SLList()
{
	while (!isEmpty())
	{
		int temp = deleteFromHead();
	}
}

bool SLList::isEmpty()
{
	return (head == NULL);
};

void SLList::addToHead(int info)
{
	if (head == NULL)
	{
		SLLNode* temp = new SLLNode;
		temp->setData(info);
		temp->setLink(NULL);
		head = temp;
	}
	else
	{
		SLLNode* temp = new SLLNode;
		temp->setData(info);
		SLLNode* next = head;
		temp->setLink(next);
		head = temp;
	}

};

void SLList::addInSorted(int e)
{
	SLLNode* pok = new SLLNode();
	pok->data = e;
	SLLNode* tmp = head;
	while (tmp->link->data < e && tmp->link != NULL)
	{
		tmp = tmp->link;
	}
	if (tmp->link->data >e)
	{
		pok->link = tmp->link;
		tmp->link = pok;
	}
};

void SLList::addToTail(int info)
{
	if (head == NULL)
	{
		SLLNode* temp = new SLLNode;
		temp->setData(info);
		temp->setLink(NULL);
		head = temp;
	}
	else
	{
		SLLNode* temp = new SLLNode;
		temp->setData(info);
		temp->setLink(NULL);
		SLLNode* temp2 = head;
		while (temp2->returnLink() != NULL)
		{
			temp2 = temp2->returnLink();
		}
		temp2->setLink(temp);
	}

};

int SLList::deleteFromHead()
{
	if (isEmpty())
		throw "Lista je prazna";
	int info = head->returnData();
	SLLNode* temp = head;
	head = head->returnLink();
	delete temp;
	return info;
};

void SLList::deleteNode(int info)
{
	if (head->returnData() == info)
	{
		SLLNode* temp = new SLLNode;
		temp = head->returnLink();
		delete head;
		head = temp;
	}
	else
	{
		SLLNode* next = head;
		SLLNode* previous = new SLLNode;
		while (next->returnData() != info && next->returnLink() != NULL)
		{
			previous = next;
			next = next->returnLink();
		}
		if (next == NULL)
			cout << "Vas element nije nadjen";
		else
		{
			previous = next->returnLink();
			delete next;
			next = previous;
		}
	}
};

void SLList::printAll()   //nece da stampa bas zadni element
{
	//SLLNode* temp = head;
	//while (temp->returnLink() != NULL)
	//{
	//	temp->print();
	//	temp = temp->returnLink();
	//}
	//temp->print();    // za stampanje i zadnjeg elementa

	SLLNode* temp = head;
	while (temp != NULL)
	{
		temp->print();
		cout << " -> ";
		temp = temp->returnLink();
	}
	cout << " NULL ";
	cout << endl;
};


SLLNode* SLList::merge(SLLNode* h1, SLLNode* h2)
{
	SLLNode *h3, *head3, *tmp1, *tmp2;
	h3 = NULL;
	head3 = NULL;
	tmp1 = h1;
	tmp2 = h2;
	while (tmp1 != NULL && tmp2 != NULL)
	{
		if (tmp1->data < tmp2->data)
		{
			if (h3 == NULL)
			{
				h3 = tmp1;
				head3 = h3;
			}
			else
			{
				h3->link = tmp1;
				h3 = h3->link;
			}
			tmp1 = tmp1->link;
		}
		else
		{
			if (h3 == NULL)
			{
				h3 = tmp2;
				head3 = h3;
			}
			else
			{
				h3->link = tmp2;
				h3 = h3->link;
			}
			tmp2 = tmp2->link;
		}
	}
	if (tmp1 != NULL)
	{
		while (tmp1 != NULL)
		{
			h3->link = tmp1;
			tmp1 = tmp1->link;
			h3 = h3->link;
		}
	}
	else if (tmp2 != NULL)
	{
			while (tmp2 != NULL)
			{
				h3->link = tmp2;
				tmp2 = tmp2->link;
				h3 = h3->link;
			}
	}
	return head3;
}

void SLList::groupDuplicates()
{
	SLLNode *tmp, *pom, *prev;
	tmp = head;
	while (tmp->link->link != NULL)
	{
		pom = tmp->link;
		prev = tmp;
		while (pom->link != NULL)
		{
			if (pom->data == tmp->data)
			{
				prev->link = pom->link;
				pom->link = tmp->link;
				tmp->link = pom;
			}
			prev = pom;
			pom = pom->link;
		}
		tmp = tmp->link;
	}
}


void SLList::movePartToEnd(int a, int b)
{
	SLLNode *prev, *nodea, *nodeb;
	SLLNode *tmp = head;
	if (head->data == a)
	{
		nodea = head;
		prev = NULL;
	}
	else
	{
		tmp = head->link;
		prev = head;
		while (tmp != NULL && tmp->data != a)
		{
			prev = tmp;
			tmp = tmp->link;
		}
		if (tmp->data == a)
		{
			nodea = tmp;
		}
		else 
			throw "Element a nije nadjen";
		while (tmp != NULL && tmp->data != b)
		{
			tmp = tmp->link;
		}
		if (tmp->data == b)
			nodeb = tmp;
		else
			throw "Element b nije nadjen";
		while (tmp->link != NULL)
			tmp = tmp->link;
		prev->link = nodeb->link;
		nodeb->link = NULL;
		tmp->link = nodea;
	}
}

void SLList::update(int v, int add)
{
	SLLNode *tmp, *pom, *prev;
	tmp = head;
	prev = NULL;
	while (tmp && tmp->data != v && tmp->link)
	{
		prev = tmp;
		tmp = tmp->link;
	}
	if (tmp->data == v)
	{
		tmp->data = v + add;
		if (add < 0)
		{
			if (prev == NULL)
				return;
			pom = head;
			prev->link = tmp->link;
			while (pom && pom->data < tmp->data)
			{
				prev = pom;
				pom = pom->link;
			}
			if (pom->data>tmp->data)
			{
				prev->link = tmp;
				tmp->link = pom;
			}
		}
	}
	else
		throw "Nije nadjena vrednost";
}

void SLList::insertionSort()
{
	SLLNode *tmp, *prev, *min, *prevt, *pom;
	prevt = NULL;
	tmp = head;
	while (tmp && tmp->link&& tmp->link->link)
	{
		prev = tmp;
		min = tmp;
		pom = tmp->link;
		while (pom && pom->link && pom->data > min->data)
		{
			prev = pom;
			pom = pom->link;
		}
		if (pom->data < min->data)
		{
			min = pom;
			if (tmp == head)
			{
				prev->link = min->link;
				min->link = tmp;
				head = min;
			}
			else
			{
				SLLNode* pom1, *pom2;
				pom1 = tmp->link;
				pom2 = min->link;
				prev->link = tmp;
				tmp->link = pom2;
				prevt->link = min;
				min->link = pom1;
			}
		}
		prevt = tmp;
		tmp = tmp->link;
	}
	tmp->link = NULL;
}