#pragma once
#include "Node.h"
#include "Stablo.h"


void main()
{
	Stablo s(16);
	s.insert(2);
	s.insert(4);
	s.insert(3);
	s.insert(6);
	s.insert(3);
	s.insert(6);
	s.print();
	cout << endl;
	cout << s.brojRaz() << endl;
}