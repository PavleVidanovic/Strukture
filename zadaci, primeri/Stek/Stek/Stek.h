#pragma once
#include "iostream"
#include "string.h"
using namespace std;


class Stek
{
private:
	int trenutno;
	int n;
	int* niz;
public:
	Stek(){niz = NULL; n = 0; trenutno = 0;}
	~Stek(){ if (niz != NULL) delete[]niz; }
	Stek(int n){ this->n = n; niz = new int[n]; trenutno = 0; }
	void push(int i)
	{
		if (trenutno == n)
			throw "Niz je pun";
		niz[trenutno++] = i;
	}
	int pop()
	{
		if (trenutno == 0)
			return 0;
		int ret = niz[trenutno - 1];
		trenutno--;
		return ret;
	}
	int getTop()
	{
		if (trenutno == 0)
			return 0;
		return niz[trenutno - 1];
	}
	void print()
	{
		for (int i = 0; i < trenutno; i++)
			cout << niz[i] << " ";
		cout << endl;
	}
	char* addlong(char* op1, char* op2)  //RADI
	{
		char* sum = new char[strlen(op1)+2];
		int m = strlen(op1) + 1;
		sum[m] = '\0';
		int i = strlen(op2)-1;
		int j = m - 1;
		while (i >= 0)
		{
			int tmp = op1[i] + op2[i] - '0' - '0' + pop();
			if (tmp > 0)
			{
				push(1);
				sum[j] = (tmp-10) + '0';
			}
			else
				sum[j] = tmp + '0';
			i--;
			j--;
		}
		if (trenutno != 0)
			sum[j] = pop() + '0';
		return sum;
	}
	bool isCorrect(char* c)
	{
		int i = 0;
		while (c[i] != '\0')
		{
			if (c[i] == '(' || c[i] == '{' || c[i] == '[')
				push(c[i]);
			else if (c[i] == ')')
			{
				if (getTop() == '(')
					pop();
			}
			else if (c[i] == ']')
			{
				if (getTop() == '[')
					pop();
			}
			else if (c[i] == '}')
			{
				if (getTop() == '{')
					pop();
			}
			i++;
		}
		if (trenutno == 0)
			return true;
		else
			return false;
	}
};

