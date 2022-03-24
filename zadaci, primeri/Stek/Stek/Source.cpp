#pragma once
#include "Stek.h"


void main()
{
	Stek s(10);
	char op1 []= "[a+b]+{[(a-b)]}";
	char* ptr1 = op1;
	char op2[] = "[a+b}-{(a-n]}";
	char* ptr2 = op2;
	if (s.isCorrect(ptr1))
		cout << "Izraz je tacan" << endl;
	else
		cout << "Izraz je netacan" << endl;
	if (s.isCorrect(ptr2))
		cout << "Izraz je tacan" << endl;
	else
		cout << "Izraz je netacan" << endl;

}