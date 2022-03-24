#include "Node.h"


Node::Node()
{
	next = NULL;
	data = NULL;
}

Node::~Node()
{
}

void Node::setData(int k)
{
	data = k;
};

void Node::setNext(Node* k)
{
	next = k;
};

void Node::print()
{
	cout << "Data: " << data << endl;
};

int Node::returnData()
{
	return data;
};

Node* Node::returnNode()
{
	return next;
};
