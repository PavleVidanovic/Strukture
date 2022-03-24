#pragma once
#include "iostream"
using namespace std;


class SLLNode
{
public:
	SLLNode()
	{
		data = NULL;
		link = NULL;
	};
	SLLNode(int info, SLLNode* next)
	{
		data = info;
		link = next;
	};
	~SLLNode()
	{
	};
	void print()
	{
		if (this == NULL)
			cout << "Ovaj cvor ne postoji" << endl;
		else
		{
			cout << "Data: " << data;
		}

	};
	bool isEqual(int el)
	{
		return (el == data);
	}

	SLLNode* returnLink()
	{
		return link;
	}

	void setLink(SLLNode* next)
	{
		link = next;
	}
	int returnData()
	{
		return data;
	};

	void setData(int info)
	{
		data = info;
	}
	
	public :
	int data;
	SLLNode* link;
};

